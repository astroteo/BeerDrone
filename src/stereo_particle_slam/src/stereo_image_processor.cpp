#include "stereo_particle_slam/stereo_image_processor.hh"

StereoImageProcessor::StereoImageProcessor(){
  this->orb = cv::ORB::create(this->max_features);
  this-> matcher = cv::DescriptorMatcher::create("BruteForce-Hamming");
}
StereoImageProcessor::~StereoImageProcessor(){}

void StereoImageProcessor::leftImageReceiveCallback(const sensor_msgs::ImageConstPtr& image_ptr)
{
  toOpenCV(image_ptr,this->left_image);

  extractORB(this->left_image, this->keypoints_left, this->features_left);
  left_extracted = true;
  /*
  try{
    toOpenCV(image_ptr,this->left_image);
  }
  catch (cv_bridge::Exception& e)
  {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
  }
  try{
    extractORB(this->left_image, this->keypoints_left, this->features_left);
    left_extracted = true;
  }
  catch(std::exception& ex)
  {
    ROS_ERROR("Impossible to extract ORB features => leftcamera!");
    return;
  }
  */

}

void StereoImageProcessor::rightImageReceiveCallback(const sensor_msgs::ImageConstPtr& image_ptr)
{

  /*
  try{
    toOpenCV(image_ptr,this->right_image);

  }
  catch (cv_bridge::Exception& e)
  {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
  }

  try{
    extractORB(this->right_image, this->keypoints_right, this->features_right);
  }
  catch(std::exception& ex)
  {
    ROS_ERROR("Impossible to extract ORB features => right camera!");
    return;
  }*/
  toOpenCV(image_ptr,this->right_image);
  extractORB(this->right_image, this->keypoints_right, this->features_right);

  matchORB();
  solveStereo();
  /*
  try{
    if (left_extracted)
    {
      matchORB();
      solveStereo();
    }
  }
  catch(std::exception& ex){
      ROS_ERROR("Impossible to match ORB features!");
      return;
    }
    */

    left_extracted = false;

}

void StereoImageProcessor::toOpenCV(const sensor_msgs::ImageConstPtr& image_ptr, cv::Mat& image)
{
  cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(image_ptr, sensor_msgs::image_encodings::BGR8);
  cv::Mat image_rgb = cv_ptr->image;
  cv::cvtColor(image_rgb, image, CV_BGR2GRAY);
}


void StereoImageProcessor::extractORB(cv::Mat& image,std::vector<cv::KeyPoint> keypoints, cv::Mat features)
{
  this->orb->detectAndCompute(image, cv::Mat(),keypoints, features);
}

void StereoImageProcessor::matchORB()
{
  // match features between left nd right camera.

  matcher->match(this->features_left,this->features_right,this->matches, cv::Mat());

  //sort matches and get up to the maximum matched features.
  std::sort(this->matches.begin(),this->matches.end());

  //(this->matches).resize(max_features_match);
    // ->->extract location of good matches

  unsigned int n_matches = max_features_match < matches.size()
                                     ?
                          max_features_match : matches.size();

  if (n_matches > 3)
  {
    for( size_t i = 0; i < n_matches; i++ )
    {
      points_left.push_back( this->keypoints_left[ matches[i].queryIdx].pt );
      points_right.push_back( this->keypoints_right[ matches[i].queryIdx].pt );
    }

    features_matched = true;
  }

}

void StereoImageProcessor::solveStereo()
{
  // Wrapping the opencv function triangulatePoints
  // documentation here https://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html#triangulatepoints

  if(features_matched)
  {
    cv::Mat frame_points3D;
    triangulatePoints(this->leftP,
                      this->rightP,
                      cv::Mat(this->points_left).reshape(this->points_left.size(),2),
                      cv::Mat(this->points_right).reshape(this->points_right.size(),2),
                      frame_points3D);
    for(int i =0; i < frame_points3D.rows; i++)
    {
        points_3d.push_back(cv::Point3f(frame_points3D.at<float>(i,0),
                                        frame_points3D.at<float>(i,1),
                                        frame_points3D.at<float>(i,2))
                            );
    }


    map_3d[matched_frames] = points_3d;
    matched_frames++;
  }

  if(save_dataset)
  {

    // info file:
    std::ofstream infofile;
    std::string infofname = "info_frame" + std::to_string(matched_frames) + ".txt";
    infofile.open (infofname, std::fstream::app);
    infofile << "frame #-" << matched_frames << std::endl;
    infofile << "extracted ORB left: " << keypoints_left.size() << std::endl;
    infofile << "extracted ORB right: " << keypoints_right.size() << std::endl;


    infofile.close();
    // save left image with extracted features
    for (auto pt : points_left)
      circle(this->left_image,pt,3, cv::Scalar(255,0,0));

    cv::imwrite("imgLeft" + std::to_string(matched_frames) + ".png",this->left_image);

    // save right image with extracted features
    for (auto pt : points_right)
      circle(this->right_image,pt,3, cv::Scalar(255,0,0));

    cv::imwrite("imgRight" + std::to_string(matched_frames) + ".png",this->right_image);

    // save keypoints in .txt
    std::string fname = "keypoints_frame" + std::to_string(matched_frames) + ".txt";

    std::ofstream kpfile;
    kpfile.open (fname, std::fstream::app);

    for (auto pt : points_3d)
      kpfile << pt.x << "," << pt.y << "," << pt.z <<std::endl;


     kpfile.close();
  }

  this->points_left.clear();
  this->points_right.clear();
  this->points_3d.clear();

  features_matched = false;

}
