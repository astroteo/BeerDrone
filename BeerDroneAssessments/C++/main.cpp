#include <dirent.h>
#include <iostream>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//#include "orbExtractor.h"
#include "matcherTriangulator.h"
#include "utility.h"



using namespace ProjectUtilities;
using namespace std;

int main(int argc, char** argv)
{
  /* Do not modify this function */
  std::string detections = "";
  std::string file_path = __FILE__;
  std::string images_path = file_path.substr(0, file_path.rfind("\\"));
  std::string images_path_in ="/home/teobaiguera/Documents/BeerDrone/Datasets/test1/"; //file_path.substr(0, file_path.rfind("\\"));
  cout << "images path: " << images_path << endl;
  std::string images_path_read_left =  images_path_in + "left/";//createPath(getParentFolder(getParentFolder(images_path)), "data/test_images/left/");
  std::string images_path_read_right = images_path_in + "right/";//ccreatePath(getParentFolder(getParentFolder(images_path)), "data/test_images/right/");
  cout << "Left images path: " << images_path_read_left << endl;
  cout << "Right images path: " << images_path_read_right <<endl;

  std::string images_path_store = createPath(getParentFolder(getParentFolder(images_path)), "data/result_images");

  std::vector<string> files_left = getImagesFromPath(images_path_read_left);
  std::vector<string> files_right =getImagesFromPath(images_path_read_right);
  files_left = sortImagesInPath(files_left,"imgLeft");
  cout << "--------------------------------------------------" << endl;
  files_right = sortImagesInPath(files_right,"imgRight");
  // instantiate features extractor
  OrbExtractor *oe_left = new OrbExtractor();
  OrbExtractor *oe_right = new OrbExtractor();

  //instantiate matcher-triangulator
  MatcherTriangulator *mt = new MatcherTriangulator(*oe_left,*oe_right);




  //4. Main loop, apply algorithm
  for (unsigned int i_frame=0 ; i_frame < files_left.size() ; i_frame++)
  {
    auto file_left = files_left[i_frame];
    auto file_right = files_right[i_frame];


    // read img
    cout << "frame #-" << i_frame <<": " << file_left << " , " << file_right << endl;
    cv::Mat frame_left = cv::imread(file_left, cv::IMREAD_COLOR);
    cv::Mat frame_right = cv::imread(file_right, cv::IMREAD_COLOR);

    // to b&w
    cv::Mat frame_left_bw, frame_right_bw;

    cv::cvtColor(frame_left, frame_left_bw, cv::COLOR_BGR2GRAY);
    cv::cvtColor(frame_right, frame_right_bw, cv::COLOR_BGR2GRAY);

    //extract features
    vector <cv::Point2f> pts_left = oe_left->getFeaturesPoints(frame_left_bw);
    vector <cv::Point2f> pts_right = oe_right->getFeaturesPoints(frame_right_bw);

    // extract & match
    vector< vector<cv::Point2f> > pts_match =  mt->getMatchedFeaturesPoints(frame_left,frame_right);

    for(auto pt : pts_left)
      cv::circle(frame_left, pt, 2,CV_RGB(0, 255, 0), -1, CV_AA);

    for(auto pt : pts_right)
      cv::circle(frame_right, pt, 2,CV_RGB(0, 255, 0), -1, CV_AA);

    for(auto pt : pts_match)
    {

      cv::circle(frame_left, pt[0], 1,CV_RGB(255, 0, 0), -1, CV_AA);
      cv::circle(frame_right, pt[1], 1,CV_RGB(255, 0, 0), -1, CV_AA);

    }

    // extract, match & triangulate, store pcl
    mt->doJob(frame_left_bw,frame_right_bw);




    string result_file_left(file_left.substr(file_left.rfind("/") + 1));
    result_file_left = "frame"+std::to_string(i_frame) + result_file_left;
    cout << result_file_left<< endl;
    string result_file_right(file_right.substr(file_right.rfind("/") + 1));
    result_file_right = "frame"+std::to_string(i_frame) + result_file_right;
    cout << result_file_right<< endl;

    string path_image_store_left = images_path_store  + "/"+ result_file_left;
    string path_image_store_right = images_path_store  + "/"+ result_file_right;

    cout << "saving result image at: "<< path_image_store_right
                                      << path_image_store_left
                                      <<endl;
    cv::imwrite(path_image_store_left,frame_left);
    cv::imwrite(path_image_store_right,frame_right);
    //match features



  }
}
