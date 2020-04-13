
#include "CImg.h"
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cimg_library;

int main(int argc, char *argv[]) 
{
    cv::Mat src = cv::imread(argv[1]);
    cv::Size size = src.size();
    CImg<unsigned char> tmp(src.cols,src.rows,1,src.channels());
    std::vector<cv::Mat> channels;
    cv::split(src,channels);
    for (int c = 0; c<src.channels(); ++c) 
    {
        CImg<unsigned char> plane = tmp.get_shared_channel(src.channels() - 1 - c);
        for (int i = 0; i<size.height; ++i) 
        {
        const unsigned char* row_i = channels[c].ptr<unsigned char>(i);
        unsigned char *row_o = plane.data(0,i);
        std::memcpy(row_o,row_i,size.width*sizeof(unsigned char));
        }
    }

    CImg<unsigned char> image2(800,600,1,3,100);
    CImgDisplay main_disp(image2,"Click a point");
    
    int i=0;
    while( !main_disp.is_closed() && (!main_disp.is_keyQ()))
    {
        ++i;
        std::cout<<"i "<<i <<std::endl;
        // main_disp.wait();
        if(i%2000<1000)
            tmp.display(main_disp);
        else
            image2.display(main_disp);

        if( i> 10000)
            break;
    }

    return 0;
}