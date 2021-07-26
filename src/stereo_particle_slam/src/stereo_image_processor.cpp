#include "stereo_particle_slam/stereo_image_processor.hh"

StereoImageProcessor::StereoImageProcessor(){
  this->orb = cv::ORB::create(this->max_features);
}
StereoImageProcessor::~StereoImageProcessor(){}

void StereoImageProcessor::leftImageReceiveCallback(const sensor_msgs::ImageConstPtr& image_ptr)
{
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
    ROS_ERROR("Impossible to extract ORB features!");
    return;
  }

}

void StereoImageProcessor::rightImageReceiveCallback(const sensor_msgs::ImageConstPtr& image_ptr)
{
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
    ROS_ERROR("Impossible to extract ORB features!");
    return;
  }

  if (left_extracted)
  {
    matchORB();
    solveStereo();
  }

  left_extracted = false;


}

void StereoImageProcessor::toOpenCV(const sensor_msgs::ImageConstPtr& image_ptr, cv::Mat& image)
{
  cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(image_ptr, sensor_msgs::image_encodings::BGR8);
  image = cv_ptr->image;
}

void StereoImageProcessor::extractORB(cv::Mat& image,std::vector<cv::KeyPoint> keypoints, cv::Mat features)
{
  this->orb->detectAndCompute(image, cv::Mat(),keypoints, features);

}

void StereoImageProcessor::matchORB()
{
  // match features between left nd right camera.
  std::vector<cv::DMatch> matches;
  matcher->match(this->features,frame_features,matches, cv::Mat());

  //sort matches and get up to the maximum matched features.
  std::sort(matches.begin(), matches.end());
  matches.resize(max_features_match);
    // ->->extract location of good matches


  unsigned int n_matches = max_features_match < matches.size()
                                     ?
                          max_features_match : matches.size();

  for( size_t i = 0; i < n_matches; i++ )
  {
    points_left.push_back( this->keypoints_left[ matches[i].queryIdx].pt );
    points_right.push_back( this->keypoints_right[ matches[i].queryIdx].pt );
  }

}

void StereoImageProcessor::solveStereo()
{
  // Wrapping the opencv function triangulatePoints
  // documentation here https://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html#triangulatepoints

}
