#pragma once
#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <string>

class OCRProcessor {
    tesseract::TessBaseAPI* ocr;
public:
    OCRProcessor();
    ~OCRProcessor();
    std::string extractText(const cv::Mat& img);
};
