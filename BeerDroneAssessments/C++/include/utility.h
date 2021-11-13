#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

namespace ProjectUtilities{
  char getFolderSeparator()
  {
    char sep = '/';
    #ifdef _WIN32
    sep = '\\';
    #endif
    return sep;
  }

  std::string getParentFolder(const std::string& s)
  {
     size_t i = s.rfind(getFolderSeparator(), s.length());
     if (i != std::string::npos) {
        return(s.substr(0, i));
     }
     return("");
  }

  std::string createPath(const std::string& base_path, const std::string& folder)
  {
    return std::string(base_path+getFolderSeparator()+folder);
  }

  void writeDetectionsToFile(const std::string &file_path, const std::string &detections)
  {
    std::fstream file;
    file.open(createPath(file_path,"results.txt"), std::ios::out);
    file << detections<<std::endl;
    file.close();
  }

  std::vector<std::string> getImagesFromPath(const std::string &images_path)
  {
    std::vector<std::string> files;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (images_path.c_str())) != NULL)
    {
      while ((ent = readdir (dir)) != NULL)
      {
        if (std::string(ent->d_name).size() > 3)
        {
          files.push_back(createPath(images_path, ent->d_name));
        }
      }
      closedir (dir);
    }
    else
    {
      perror ("Directory does not exist");
    }
    return files;
  }

  std::vector<std::string> sortImagesInPath(  std::vector<std::string> images_path, std::string cmp_str)
  {
    map<int,string> mapper;
    map<int,string>::iterator it_mapper;


    std::vector<string> sorted_paths;

    for(auto s : images_path)
    {
      //cout << s << endl;
      bool flg_ss = false;
      std::size_t pos_end = s.find(".png");
      std::size_t pos_start = 0;
      int add_ = 0;
      if(cmp_str == "imgLeft")
      {
        add_ = 7;
      }
      else if(cmp_str == "imgRight")
      {
        add_ = 8;
      }
      if (s.find(cmp_str))
      {
           flg_ss = true;
           pos_start = s.find(cmp_str);//pos_end-4;//s.find("/imgLeft/");
           pos_start+=add_;
      }


      if(flg_ss)
      {
        cout << pos_start <<"," << pos_end << endl;

        std::string sstr = s.substr(pos_start,pos_end -pos_start);
        //cout << "=>" << sstr << endl;

        int frame_n = stoi(sstr);
        //cout << "=>=>" << frame_n << endl;

        mapper[frame_n] = s;
      }
    }



      for (auto mp : mapper)
        sorted_paths.push_back(mp.second);

      return sorted_paths;


    }

  map<string,string> parseIniFile(const string config_file)
  {
    cout <<"Parsing config file..."<<endl;
    map<string,string> config_map;
    ifstream infile(config_file);

    string line;
    while(getline(infile, line))
    {
      //cout << line << endl;
      if(line[0] != '#')
      {
        istringstream _line(line);
        string key;
        if( std::getline(_line, key, '=') )
        {
          string value;
          if(getline(_line, value))
            config_map[key] = value;
        }
    }
  }

    return config_map;
  }

  cv::Mat imageToBnW(cv::Mat rgb_image)
  {
    cv::Mat gray_image;
    cv::cvtColor(rgb_image,gray_image,cv::COLOR_BGR2GRAY);

    return gray_image;
  }

  cv::Mat imageToBnW(string path)
  {
    cv::Mat rgb_image = cv::imread(path,cv::IMREAD_COLOR);
    cv::Mat gray_image;
    cv::cvtColor(rgb_image,gray_image,cv::COLOR_BGR2GRAY);

    return gray_image;
  }

  cv::Mat backgroundSubtraction(string image_path)
  {

    int history = 1;
    float var_threshold = 16;
    bool bshadow_detection = false;

    cv::Ptr<cv::BackgroundSubtractor> pBackSub =
                                      cv::createBackgroundSubtractorMOG2(history,
                                                                         var_threshold,
                                                                         bshadow_detection);
    // Remove color
    cv::Mat img = imageToBnW(image_path);//

    //Subtract background
    cv::Mat fg_mask;
    pBackSub->apply(img,fg_mask);

    return fg_mask;
  }

  template<typename _Tp> static  cv::Mat toMat(const vector<vector<_Tp> > vecIn) {
    cv::Mat_<_Tp> matOut(vecIn.size(), vecIn.at(0).size());
    for (int i = 0; i < matOut.rows; ++i) {
        for (int j = 0; j < matOut.cols; ++j) {
            matOut(i, j) = vecIn.at(i).at(j);
        }
    }
    return matOut;
}
}
