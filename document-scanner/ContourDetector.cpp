#include "ContourDetector.h"
#include <algorithm>

std::vector<cv::Point> ContourDetector::getContours(const cv::Mat& image) {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::vector<std::vector<cv::Point>> conPoly(contours.size());
    std::vector<cv::Point> biggest;
    int maxArea = 0;

    for (int i = 0; i < contours.size(); i++) {
        int area = cv::contourArea(contours[i]);
        if (area > 1000) {
            float peri = cv::arcLength(contours[i], true);
            cv::approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            if (area > maxArea && conPoly[i].size() == 4) {
                biggest = conPoly[i];
                maxArea = area;
            }
        }
    }
    return biggest;
}

std::vector<cv::Point> ContourDetector::reorder(const std::vector<cv::Point>& points) {
    std::vector<cv::Point> newPoints(4);
    std::vector<int> sumPoints, subPoints;

    for (const auto& p : points) {
        sumPoints.push_back(p.x + p.y);
        subPoints.push_back(p.x - p.y);
    }

    newPoints[0] = points[std::min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()];
    newPoints[1] = points[std::max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()];
    newPoints[2] = points[std::min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()];
    newPoints[3] = points[std::max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()];

    return newPoints;
}
