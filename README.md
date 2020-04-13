### CImg 
[CImg](https://github.com/dtschump/CImg) is a light C++ library for image processing. Compared with the OpenCV, CImg contains only a single header file, which makes it more convenient to use. When we just need a few image processing functions in project, this library should be quite useful.

This reposity is based on CImg library. And we'll show the fantastic functions in CImg. 

### How to use 
1. build the project 
```
mkdir build 
cd build 
cmake .. 
make -j
```

2. run the demo 
```
./test_image <path_to_image>
./test_video <path_to_video>
```

**in order to run the demo, OpenCV is necessary.**

### Task lists
- [x] cv::Mat to CImg  
- [ ] how to do deblur  


### Reference  
CImg: https://github.com/dtschump/CImg