

#include <ros/ros.h>
#include "stereo_particle_slam/stereo_image_processor.hh"
#include <string>

#define DATASET_CREATE true;
#define DATASET_PATH  "/home/teobaiguera/Documents/BeerDrone/Datasets/test1/";


int main(int argc, char* argv[])
{
  // This must be called before anything else ROS-related
  ros::init(argc, argv, "vision_node");

  // Create a ROS node handle
  ros::NodeHandle nh;

  cv::Mat left_image,right_image;

  //Create image processor
  StereoImageProcessor sip;
  sip.save_dataset = true;
  std::string dataset_path_ = "/home/teobaiguera/Documents/BeerDrone/Datasets/test1";
  sip.dataset_path = DATASET_PATH;


  // Suscribe to left and right camera topics:
  image_transport::ImageTransport it_left(nh);
  image_transport::Subscriber sub_left =
                            it_left.subscribe("/stereo/left/image_raw", 10, &StereoImageProcessor::leftImageReceiveCallback, &sip);

  image_transport::ImageTransport it_right(nh);
  image_transport::Subscriber sub_right =
                            it_right.subscribe("/stereo/right/image_raw", 10, &StereoImageProcessor::rightImageReceiveCallback, &sip);

  // Set camera matrices, as intercepted from topics:  /stereo/right/camera_info
 //                                                   /stereo/left/camera_info

  //float leftKData[9] = {238.3515418007097, 0.0, 200.5, 0.0, 238.3515418007097, 200.5, 0.0, 0.0, 1.0};
  //cv::Mat leftK_ = cv::Mat(3,3,CV_32F,leftKData);
  //    --> real hardware might require to generate the projection matrix for each camera with cv::stereoRectify()
  float leftPData[12] = {238.3515418007097, 0.0, 200.5, -0.0, 0.0, 238.3515418007097, 200.5, 0.0, 0.0, 0.0, 1.0, 0.0};
  sip.leftP = cv::Mat(3,4,CV_32F,leftPData);

  float rightPData[12] = {238.3515418007097, 0.0, 200.5, -16.68460792604968, 0.0, 238.3515418007097, 200.5, 0.0, 0.0, 0.0, 1.0, 0.0};
  sip.rightP = cv::Mat(3,4,CV_32F,rightPData);

  // Don't exit the program.
  ros::spin();
}
