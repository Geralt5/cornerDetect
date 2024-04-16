#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main() {
    // Load the image on which to draw corners
    Mat image = imread("img1.png");
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Load corner data from XML
    FileStorage fs("test.xml", FileStorage::READ);
    vector<Point> corners;
    fs["img_corners_a1"] >> corners;
    fs.release();

    // Draw each corner
    for (const Point& corner : corners) {
        circle(image, corner, 5, Scalar(0, 255, 0), -1);
    }

    // Save the image with corners marked
    bool isSuccess = imwrite("Corners_Detected.png", image);
    if (!isSuccess) {
        cout << "Failed to save the image" << endl;
        return -1;
    }

    cout << "Image saved successfully" << endl;

    return 0;
}
