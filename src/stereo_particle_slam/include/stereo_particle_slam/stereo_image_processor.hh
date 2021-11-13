#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
 //#include <opencv2/nonfree/xfeatures2d.hpp>
//# include "opencv2/nonfree/features2d.hpp"
//#include<opencv2/features2d/features2d.hpp>
#include <opencv2/features2d.hpp>
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
    void extractORB(cv::Mat& image,std::vector<cv::KeyPoint> keypoints, cv::Mat features);
    void matchORB();
    void solveStereo();
  // Create empty opencv mat
  public:
    // raw images
    cv::Mat left_image,right_image;

    // features extractor, features, keypoints, features matcher
    int max_features = 500;
    int max_features_match= 50;
    cv::Ptr<cv::Feature2D> orb;
    cv::Ptr<cv::DescriptorMatcher> matcher;
    cv::Mat features_left, features_right;
    std::vector<cv::DMatch>matches;
    std::vector<cv::KeyPoint> keypoints_left, keypoints_right;
            //all extracted features positions
    std::vector<cv::Point2f> points_left, points_right;
            //MATCHED extracted features positions

    int matched_frames = 0;
    int cnt_save_frames =0;
    std::vector<cv::Point3f> points_3d;
    std::map<int,std::vector<cv::Point3f>> map_3d;
            // triangulated 3D points.



    // data-storage settings.
    bool save_dataset = false;
    std::string dataset_path = "";
    // camera matrices
    //cv::Mat leftK,leftP, rightK, rightP;
    cv::Mat leftP, rightP;

    // extraction,matcher & triangulation done flags
    bool left_extracted = false;
    bool features_matched = false;
    bool triangulation_done = false;


};
