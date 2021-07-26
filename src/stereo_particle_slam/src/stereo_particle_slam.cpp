

#include <ros/ros.h>
#include "stereo_particle_slam/stereo_image_processor.hh"


#define DATASET_CREATE true;
#define DISPARITY_MAP_DATASET_PATH  "/home/teobaiguera/Documents/BeerDrone/Datasets/DisparityMaps/";


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
  sip.save_disparity_map_path = DISPARITY_MAP_DATASET_PATH;


  // Suscribe to left and right camera topics.
  image_transport::ImageTransport it_left(nh);
  image_transport::Subscriber sub_left =
                            it_left.subscribe("/stereo/left/image_raw", 1000, &StereoImageProcessor::leftImageReceiveCallback, &sip);

  image_transport::ImageTransport it_right(nh);
  image_transport::Subscriber sub_right =
                            it_right.subscribe("/stereo/right/image_raw", 1000, &StereoImageProcessor::rightImageReceiveCallback, &sip);



  // Don't exit the program.
  ros::spin();
}
