#ifndef DETECTOR_H
#define DETECTOR_H


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <omp.h>
#include <opencv2/core/core.hpp>
using namespace cv;
using namespace std;
using std::vector;

class FindCorners
{
public:
	FindCorners();
	FindCorners(Mat img);

	~FindCorners();

public:
	void detectCorners(Mat &Src, vector<Point> &resultCornors,float scoreThreshold, int num_threads);

private:
	float normpdf(float dist, float mu, float sigma);
	void getMin(Mat src1, Mat src2, Mat &dst);
	void getMax(Mat src1, Mat src2, Mat &dst);
	void getImageAngleAndWeight(Mat img, Mat &imgDu, Mat &imgDv, Mat &imgAngle, Mat &imgWeight);
	void edgeOrientations(Mat imgAngle, Mat imgWeight,int index);
	void findModesMeanShift(vector<float> hist, vector<float> &hist_smoothed, vector<pair<float, int>> &modes, float sigma);
	void scoreCorners(Mat img, Mat imgAngle, Mat imgWeight, vector<Point> &cornors, vector<int> radius, vector<float> &score);
	void cornerCorrelationScore(Mat img, Mat imgWeight, vector<Point2f> cornersEdge, float &score);
	void refineCorners(vector<Point> &cornors, Mat imgDu, Mat imgDv, Mat imgAngle, Mat imgWeight, float radius);
	void createkernel(float angle1, float angle2, int kernelSize, Mat &kernelA, Mat &kernelB, Mat &kernelC, Mat &kernelD);
	void nonMaximumSuppression(Mat& inputCorners, vector<Point>& outputCorners, float threshold, int margin, int patchSize);
	void FindCorners::createkernel(float angle1, float angle2, int kernelSize, Mat &kernelA, Mat &kernelB, Mat &kernelC, Mat &kernelD);
	void FindCorners::getMin(Mat src1, Mat src2, Mat &dst);
	void FindCorners::getMax;

private:
	vector<Point2f> templateProps;
	vector<int> radius;
	vector<Point> cornerPoints;
	std::vector<std::vector<float> > cornersEdge1;
	std::vector<std::vector<float> > cornersEdge2;
	std::vector<cv::Point* > cornerPointsRefined;

};

#endif // DETECTOR_H
