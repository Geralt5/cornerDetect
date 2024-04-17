// CalibrationADAS.cpp : 定义控制台应用程序的入口点。
//


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <algorithm>
#include "FindCorners.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <fnmatch.h>
#include <string>
#include <glob.h>
#include <vector>
#include <omp.h>
#include <dirent.h>  
using namespace cv;
using namespace std;
using std::vector;
vector<Point2i> points;

int main(int argc, char* argv[])
{
  Mat src; 
  cout << "This is a demo for corner detection." << endl;

  // //add file procedure
  // std::string images_dir = "calibration/images";  // Adjust path if needed
  // std::vector<std::string> image_paths;

  // // Iterate through files in the directory (portable approach)
  // DIR* dir;
  // struct dirent* entry;
  // dir = opendir(images_dir.c_str());
  //   if (!dir) {
  //     std::cerr << "Error opening directory: " << images_dir << std::endl;
  //     return -1;
  //       }
  //   while ((entry = readdir(dir)) != nullptr) {
  //     std::string filename = entry->d_name;
  //     if (filename != "." && filename != "..") {  // Skip "." and ".."
  //         if (filename.find(".png") != std::string::npos) {  // Check for PNG extension
  //           image_paths.push_back(images_dir + "/" + filename);
  //         }
  //     }
  // }
  // closedir(dir);

      
  // for (const std::string& path : image_paths) {
  //         /// Read the image file
  //         Mat src = imread(path, -1);
  //         if (src.empty()) {
  //             std::cerr << "Error reading image: " << path << std::endl;
  //           continue;}
  //     // Detect corners in the image
  //     vector<Point> corners;
  //     FindCorners corner_detector(src);
  //     corner_detector.detectCorners(src, corners, 0.025);
  // }
 
  string filename = "img1.png";
  src = imread(filename, -1);
  if (src.empty())
  {
    printf("Cannot read image file: %s\n", filename.c_str());
    return -1;
  }
  int num_threads;
  if (argc < 2) {
        num_threads = 1;  // You can set this to any default you see fit
        cout << "No thread number provided. Using default: " << num_threads << endl;
    } else {
        num_threads = atoi(argv[1]);
        cout << "Number of threads: " << num_threads << endl;
    }
  vector<Point> corners;
  FindCorners corner_detector(src);
  corner_detector.detectCorners(src, corners,0.025, num_threads);
  return 0;
}

