#include "OCRProcessor.h"
#include <iostream>

OCRProcessor::OCRProcessor() {
    ocr = new tesseract::TessBaseAPI();
    if (ocr->Init("C:/Program Files/Tesseract-OCR/tessdata", "eng")) {
        std::cerr << "Could not initialize tesseract.\n";
        exit(1);
    }
}

std::string OCRProcessor::extractText(const cv::Mat& img) {
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    ocr->SetImage(gray.data, gray.cols, gray.rows, 1, gray.step);
    char* outText = ocr->GetUTF8Text();
    std::string result(outText);
    delete[] outText;
    return result;
}

OCRProcessor::~OCRProcessor() {
    ocr->End();
    delete ocr;
}
