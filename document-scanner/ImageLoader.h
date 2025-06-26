#pragma once
#include <opencv2/opencv.hpp>

class ImageLoader {
public:
    static cv::Mat loadImage(int choice);
};
