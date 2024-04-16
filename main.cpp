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
#include <dirent.h>  
using namespace cv;
using namespace std;
using std::vector;
vector<Point2i> points;

int main(int argc, char* argv[])
{
	//Mat kernels;
	//FileStorage fs2("templateA1.xml", FileStorage::READ);//读XML文件
	//fs2["templateA1"] >> kernels;
	//cout << "kernels: " << kernels << endl;

	//读入原始图像
	Mat src; //输入图像
	cout << "This is a demo for Parking slot detection." << endl;

        //add file procedure
        
        std::string images_dir = "calibration/images";  // Adjust path if needed
        std::vector<std::string> image_paths;

       // Iterate through files in the directory (portable approach)
        DIR* dir;
        struct dirent* entry;
        dir = opendir(images_dir.c_str());
          if (!dir) {
            std::cerr << "Error opening directory: " << images_dir << std::endl;
            return -1;
             }
         while ((entry = readdir(dir)) != nullptr) {
           std::string filename = entry->d_name;
           if (filename != "." && filename != "..") {  // Skip "." and ".."
               if (filename.find(".png") != std::string::npos) {  // Check for PNG extension
                  image_paths.push_back(images_dir + "/" + filename);
               }
           }
        }
        closedir(dir);

        
 //       glob("calibration/images/*.png", GLOB_BRACE, nullptr, &image_paths);
        // Loop through all images in the directory
        for (const std::string& path : image_paths) {
               /// Read the image file
               Mat src = imread(path, -1);
               if (src.empty()) {
                   std::cerr << "Error reading image: " << path << std::endl;
                 continue;}
            // Detect corners in the image
            vector<Point> corners;
            FindCorners corner_detector(src);
            corner_detector.detectCorners(src, corners, 0.025);
            // Display the image with detected corners
            //for (const Point& corner : corners) {                                           circle(src, corner, 5, Scalar(0, 0, 255), -1);
            //}
            //imshow("Corner Detection", src);                                                waitKey(0);
            //}
        }
 
	//string filename = "img1.png";//图像路径位置 "Img\\birdView0015.png"   calib\\_70.png
	//src = imread(filename, -1);//载入测试图像
	//if (src.empty())//不能读取图像
	//{
	//	printf("Cannot read image file: %s\n", filename.c_str());
	//	return -1;
	//}
        

	//vector<Point> corners;//存储找到的角点
	//FindCorners corner_detector(src);
	//corner_detector.detectCorners(src, corners,0.025);
	return 0;
}

