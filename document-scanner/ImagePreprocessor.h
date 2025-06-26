#pragma once
#include <opencv2/opencv.hpp>

class ImagePreprocessor {
public:
    static cv::Mat preprocess(const cv::Mat& img);
};
