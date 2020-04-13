### CImg_library 
a light C++ library for image processing. 

here, we just use its display function. 

#### How to use 
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

#### Task lists
- [x] cv::Mat to CImg  
- [ ] how to do deblur  


#### Reference   

[CImg](https://github.com/dtschump/CImg)