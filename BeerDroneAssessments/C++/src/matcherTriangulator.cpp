#include "matcherTriangulator.h"
  /*
  matcherTriangulator::matcherTriangulator():
  {
    max_features_match = 500;
  }
*/
//  MatcherTriangulator::  MatcherTriangulator() : left_oe(NULL), right_oe(NULL) ;

  MatcherTriangulator::MatcherTriangulator(OrbExtractor& left_oe_,OrbExtractor& right_oe_) : left_oe(left_oe_), right_oe(right_oe_)
  {
    max_features_match = 500;
    this-> matcher = cv::DescriptorMatcher::create("BruteForce-Hamming");

    //assign default calib matrices:
    double PlData[] = {238.3515418007097, 0.0, 200.5, -0.0,               0.0, 238.3515418007097, 200.5, 0.0, 0.0, 0.0, 1.0, 0.0};
    double PrData[] = {238.3515418007097, 0.0, 200.5, -16.68460792604968, 0.0, 238.3515418007097, 200.5, 0.0, 0.0, 0.0, 1.0, 0.0};

    cv::Mat Pl_ = cv::Mat(3,4,CV_64FC1,PlData);
    cv::Mat Pr_ = cv::Mat(3,4,CV_64FC1,PrData);


    this->Pl = Pl_;
    this->Pr = Pr_;
  }

  void
  MatcherTriangulator::doJob(const cv::Mat& frame_image_left,const cv::Mat& frame_image_right)
  {
    // extract ORB
    left_oe.doJob(frame_image_left);
    right_oe.doJob(frame_image_right);

    //match orb
    matcher->match(this->left_oe.features,this->right_oe.features,this->matches, cv::Mat());

    //sort matches and get up to the maximum matched features.
    std::sort(this->matches.begin(),this->matches.end());

    unsigned int n_matches = max_features_match < matches.size()
                                       ?
                            max_features_match : matches.size();


    //triangulate best matches.
    vector<cv::Point2d>  lpts, rpts;
    for( size_t i = 0; i < n_matches; i++ )
    {
        lpts.push_back((cv::Point2d)left_oe.keypoints[ matches[i].trainIdx].pt);
        rpts.push_back((cv::Point2d)right_oe.keypoints[ matches[i].trainIdx].pt);
    }

    cv::triangulatePoints(this->Pl,this->Pr,
                          lpts,rpts ,
                          this->points3dMat);

    for (size_t i=0; i< points3dMat.cols; i++)
    {
      //https://gist.github.com/cashiwamochi/8ac3f8bab9bf00e247a01f63075fedeb
      cv::Mat p3d =  points3dMat.col(i);
      //cv::Mat _p3h = point3d_homo.col(i);
      //convertPointsFromHomogeneous(_p3h.t(), p3d);
      double x = p3d.at<double>(0);
      double y = p3d.at<double>(1);
      double z = p3d.at<double>(2);

      cout << "x: " << x <<  " y: " << y << " z: " << z << endl;
    }

    // erase extractors
    left_oe.erase();
    right_oe.erase();
  }

  vector< vector<cv::Point2f> >
  MatcherTriangulator::getMatchedFeaturesPoints(const cv::Mat& frame_image_left,const cv::Mat& frame_image_right)
  {
    // extract ORB
    left_oe.doJob(frame_image_left);
    right_oe.doJob(frame_image_right);

    //match orb
    matcher->match(this->left_oe.features,this->right_oe.features,this->matches, cv::Mat());

    //sort matches and get up to the maximum matched features.
    std::sort(this->matches.begin(),this->matches.end());

    unsigned int n_matches = max_features_match < matches.size()
                                       ?
                            max_features_match : matches.size();


    vector< vector<cv::Point2f> > matched_points;//(vector<cv::Point2f>,2);

    for( size_t i = 0; i < n_matches; i++ )
    {

        vector<cv::Point2f> duple;
        duple.push_back(left_oe.keypoints[ matches[i].trainIdx].pt );
        duple.push_back(right_oe.keypoints[ matches[i].trainIdx].pt );

        matched_points.push_back(duple);//left_oe.keypoints[ matches[i].queryIdx].pt ;
        //matched_points[i,1] = right_oe.keypoints[ matches[i].trainIdx].pt ;
    }

    left_oe.erase();
    right_oe.erase();


    return matched_points;
  }
