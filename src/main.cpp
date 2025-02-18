#include <iostream>
#include <opencv2/opencv.hpp>


int main() {
    cv::Mat image = cv::Mat::zeros(2160, 3480, CV_8UC3);
    cv::line(image, cv::Point(50, 50), cv::Point(200, 200), cv::Scalar(255, 255, 255), 1);

    imshow("Display window", image);
    cv::waitKey(0);

    if (!imwrite("result.jpg", image)) {
        std::cerr << "Error saving the image" << std::endl;
        return -1;
    }

    std::cout << "Image saved as result.jpg" << std::endl;
    return 0;
}