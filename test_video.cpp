#include "CImg.h"
#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/video/video.hpp>

using namespace cimg_library;

void mat2CImg(cv::Mat &frame, CImg<unsigned char> &cimg)
{
    CImg<unsigned char> tmp(frame.cols,frame.rows,1,frame.channels());
    std::vector<cv::Mat> channels;
    cv::split(frame,channels);
    for (int c = 0; c<frame.channels(); ++c) 
    {
        CImg<unsigned char> plane = tmp.get_shared_channel(frame.channels() - 1 - c);
        for (int i = 0; i<frame.rows; ++i) 
        {
        const unsigned char* row_i = channels[c].ptr<unsigned char>(i);
        unsigned char *row_o = plane.data(0,i);
        std::memcpy(row_o,row_i,frame.cols*sizeof(unsigned char));
        }
    }
    std::swap(cimg, tmp);
}


int main(int argc, char *argv[])
{
    std::string video_path = argv[1];
    cv::VideoCapture video_capture(video_path);
    assert(video_capture.isOpened());

    cv::Mat frame;
    video_capture >> frame;

    CImg<unsigned char> cimg;

    CImg<unsigned char> image2(800,600,1,3,100);
    CImgDisplay main_disp(image2,"Click a point"); 

    while(!main_disp.is_closed() && !main_disp.is_keyQ())
    {
        video_capture >> frame;
        if(frame.empty())
        {
            break;
        }

        mat2CImg(frame, cimg);
        cimg.display(main_disp);
    }

    return 0;
}

