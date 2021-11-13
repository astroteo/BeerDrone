#include <iostream>
#include <opencv2/opencv.hpp>
//Additional include w.r.t. assignment
//#include <opencv2/xfeatures2d.hpp>
#include <opencv2/features2d.hpp>
#include <math.h>

using namespace std;

class OrbExtractor
{
public:
  OrbExtractor();
  vector<cv::Point2f> getFeaturesPoints(const cv::Mat& frame_image);
  void doJob(const cv::Mat& frame_image);
  void erase();

  public:
    // ORB core algoritm and matcher
    cv::Ptr<cv::Feature2D> orb;
    //cv::Ptr<cv::DescriptorMatcher> matcher;

    // ORB hyper-parameter for features extraction and matching
    unsigned int max_features;// max_features_match;

    // keypoints (reference image)
    std::vector<cv::KeyPoint> keypoints;
    cv::Mat features;

};
