# CornerDetect
Realization of "Automatic Camera and Range Sensor Calibration using a single Shot" by C++;
This is a key work to detect checkerboard corners and plays a role in camera calibration.
![image](https://github.com/qibao77/cornerDetect/blob/master/cornor_detect.png)
# Reference
Geiger A, Moosmann F, Car Ö, et al. Automatic camera and range sensor calibration using a single shot[C]//Robotics and Automation (ICRA), 2012 IEEE International Conference on. IEEE, 2012: 3936-3943.

Make sure you have opencv installed
Complie with: g++ -std=c++11 main.cpp FindCorners.cpp -o main `pkg-config --cflags --libs opencv`
