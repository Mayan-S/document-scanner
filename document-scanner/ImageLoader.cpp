#include "ImageLoader.h"
#include <sstream>

cv::Mat ImageLoader::loadImage(int choice) {
    std::stringstream ss;
    ss << "Resources/document_" << choice << ".jpg";
    return cv::imread(ss.str());
}
