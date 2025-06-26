#include "Application.h"
#include "ImageLoader.h"
#include "ImagePreprocessor.h"
#include "ContourDetector.h"
#include "DocumentScanner.h"
#include "OCRProcessor.h"
#include "ResultWriter.h"

#include <opencv2/opencv.hpp>
#include <iostream>

void Application::run() {
    float width = 420, height = 596;
    int choice = getUserChoice();
    cv::Mat imgOriginal = ImageLoader::loadImage(choice);
    cv::Mat imgThre = ImagePreprocessor::preprocess(imgOriginal);

    std::vector<cv::Point> initialPoints = ContourDetector::getContours(imgThre);
    cv::Mat imgCrop;

    if (initialPoints.empty()) {
        imgCrop = imgOriginal.clone();
    }
    else {
        std::vector<cv::Point> docPoints = ContourDetector::reorder(initialPoints);
        double docArea = cv::contourArea(initialPoints);
        double imgArea = imgOriginal.cols * imgOriginal.rows;
        double areaRatio = docArea / imgArea;

        if (areaRatio < 0.01 || areaRatio > 0.95) {
            imgCrop = imgOriginal.clone();
        }
        else {
            DocumentScanner scanner(width, height);
            cv::Mat imgWarp = scanner.warp(imgOriginal, docPoints);
            imgCrop = scanner.crop(imgWarp);
        }
    }

    ResultWriter::saveImage("Results/output.jpg", imgCrop);
    cv::imshow("Original Image", imgOriginal);
    cv::imshow("Scanned Image", imgCrop);
    cv::waitKey(0);

    OCRProcessor ocr;
    std::string text = ocr.extractText(imgCrop);
    std::cout << "\nRecognized Text:\n" << text << std::endl;

    ResultWriter::saveText("Results/output.txt", text);
    std::cout << "Results saved to 'Results/output.jpg' and 'Results/output.txt'" << std::endl;
}

int Application::getUserChoice() {
    int choice;
    std::cout << "Which Document Would You Like To Scan (#1-#8): ";
    std::cin >> choice;
    while (std::cin.fail() || choice < 1 || choice > 8) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Which Document Would You Like To Scan (#1-#8): ";
        std::cin >> choice;
    }
    return choice;
}
