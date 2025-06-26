#include "DocumentScanner.h"

DocumentScanner::DocumentScanner(float w, float h) : width(w), height(h) {}

cv::Mat DocumentScanner::warp(const cv::Mat& img, const std::vector<cv::Point>& points) {
    cv::Point2f src[4] = { points[0], points[1], points[2], points[3] };
    cv::Point2f dst[4] = { {0.0f, 0.0f}, {width, 0.0f}, {0.0f, height}, {width, height} };

    cv::Mat matrix = cv::getPerspectiveTransform(src, dst);
    cv::Mat imgWarp;
    cv::warpPerspective(img, imgWarp, matrix, cv::Point(width, height));
    return imgWarp;
}

cv::Mat DocumentScanner::crop(const cv::Mat& imgWarp) {
    int cropVal = 5;
    cv::Rect roi(cropVal, cropVal, width - 2 * cropVal, height - 2 * cropVal);
    return imgWarp(roi);
}
