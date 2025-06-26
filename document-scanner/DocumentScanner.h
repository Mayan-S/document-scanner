#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

class DocumentScanner {
private:
    float width, height;
public:
    DocumentScanner(float w, float h);
    cv::Mat warp(const cv::Mat& img, const std::vector<cv::Point>& points);
    cv::Mat crop(const cv::Mat& imgWarp);
};
