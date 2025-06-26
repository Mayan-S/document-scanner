#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

class ContourDetector {
public:
    static std::vector<cv::Point> getContours(const cv::Mat& image);
    static std::vector<cv::Point> reorder(const std::vector<cv::Point>& points);
};
