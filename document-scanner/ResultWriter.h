#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class ResultWriter {
public:
    static void saveImage(const std::string& path, const cv::Mat& img);
    static void saveText(const std::string& path, const std::string& text);
};
