#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// 
#include <opencv2/xfeatures2d.hpp>
#include "opencv2/imgcodecs.hpp"
#include <image_transport/image_transport.h>
#include <string>
#include <cv_bridge/cv_bridge.h>
#include <vector>

class StereoImageProcessor
{
  public:
    StereoImageProcessor();
    ~StereoImageProcessor();
    void leftImageReceiveCallback(const sensor_msgs::ImageConstPtr& image_ptr);
    void rightImageReceiveCallback(const sensor_msgs::ImageConstPtr& image_ptr);
    void toOpenCV(const sensor_msgs::ImageConstPtr& image_ptr, cv::Mat& image);
    void extractORB(cv::Mat& image);
    void matchORB();
    void solveStereo();
  // Create empty opencv mat
  public:
    // raw images
    cv::Mat left_image,right_image;

    // features extractor, features, keypoints, features matcher
    int max_features = 5000;
    int max_features_match= 50;
    cv::Ptr<cv::Feature2D> orb;
    cv::Ptr<cv::DescriptorMatcher> matcher;
      cv::Mat features_left, features_right;
    std::vector<cv::KeyPoint> keypoints_left, keypoints_right;
            //all extracted features positions
    std::vector<cv::Point2f> points_left, points_right;
            //MATCHED extracted features positions

    bool left_extracted = false;
    // data-storage settings.
    bool save_dataset = false;
    std::string save_disparity_map_path = "";


};
