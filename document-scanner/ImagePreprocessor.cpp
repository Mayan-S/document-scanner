#include "ImagePreprocessor.h"

cv::Mat ImagePreprocessor::preprocess(const cv::Mat& img) {
    cv::Mat gray, blur, canny, dil;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, blur, cv::Size(3, 3), 3, 0);
    cv::Canny(blur, canny, 25, 75);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(canny, dil, kernel);
    return dil;
}
