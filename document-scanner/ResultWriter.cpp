#include "ResultWriter.h"
#include <fstream>
#include <iostream>

void ResultWriter::saveImage(const std::string& path, const cv::Mat& img) {
    cv::imwrite(path, img);
}

void ResultWriter::saveText(const std::string& path, const std::string& text) {
    std::ofstream outFile(path);
    if (!outFile) {
        std::cerr << "Cannot open file for writing: " << path << std::endl;
        return;
    }
    outFile << text;
    outFile.close();
}
