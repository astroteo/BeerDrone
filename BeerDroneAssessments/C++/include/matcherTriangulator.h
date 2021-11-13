#include "orbExtractor.h"
#include <array>
using namespace std;

class MatcherTriangulator
{
public:
  //MatcherTriangulator() : left_oe(NULL), right_oe(NULL) ;
  MatcherTriangulator(OrbExtractor& left_oe_,OrbExtractor& right_oe_);
  void doJob(const cv::Mat& frame_image_left,const cv::Mat& frame_image_right);
  vector< vector<cv::Point2f> > getMatchedFeaturesPoints(const cv::Mat& frame_image_left,const cv::Mat& frame_image_right);

public:
  OrbExtractor& left_oe, right_oe;
  cv::Ptr<cv::DescriptorMatcher> matcher;
  std::vector<cv::DMatch>matches;
  unsigned int max_features_match;
  cv::Mat features;
  std::vector<cv::KeyPoint> keypoints_left;
  cv::Mat Pl,Pr;//(3,4,CV_64FC1),Pr(3,4,CV_64FC1);
  cv::Mat points3dMat;


  //camera properties:

};
