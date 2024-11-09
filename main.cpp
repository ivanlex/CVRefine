#include "core/Application.h"
#include <opencv2/opencv.hpp>
#include <mlpack.hpp>

int main() {
    cv::Mat mat = cv::imread(TEST_IMAGE, cv::IMREAD_GRAYSCALE);
    cv::imshow("Result", mat);
    LOG("Hi.");

    cv::waitKey();
    cv::destroyAllWindows();
}
