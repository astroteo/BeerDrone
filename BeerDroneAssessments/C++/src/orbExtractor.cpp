#include "orbExtractor.h"

OrbExtractor::OrbExtractor()
{
  max_features = 500;
  this->orb = cv::ORB::create(this->max_features);

}

vector<cv::Point2f>
OrbExtractor::getFeaturesPoints(const cv::Mat& frame_image)
{
  std::vector<cv::KeyPoint> frame_keypoints;
  cv::Mat frame_features;
  this->orb->detectAndCompute(frame_image, cv::Mat(),frame_keypoints, frame_features);
  cout << "detected keypoints: "<< endl;
  vector<cv::Point2f> points_;

  for (auto kp : frame_keypoints)
  {
    cout << "x: "<< kp.pt.x << "y: " << kp.pt.y << endl;
    points_.push_back(kp.pt);
  }

  return points_;

}

void
OrbExtractor::erase()
{
  this->keypoints.clear();
  this->features.release();
}


void
OrbExtractor::doJob(const cv::Mat& frame_image)
{
  this->orb->detectAndCompute(frame_image, cv::Mat(),this->keypoints, this->features);
  cout << "detected keypoints: "<< endl;
  for (auto kp : this->keypoints)
    cout << "x: "<< kp.pt.x << "y: " << kp.pt.y << endl;


}
