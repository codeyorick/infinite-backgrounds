#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

#include "../include/RepeatingRow.h"
#include "../include/Row.h"
#include "../include/StepFigure.h"

void overlay(const cv::Scalar& color, cv::Mat& background, cv::Mat& alpha, const double opacity = 1.0)
{
    alpha *= opacity;

    cv::Mat foreground(background.size(), background.type(), color);

    foreground.convertTo(foreground, CV_32FC3);
    background.convertTo(background, CV_32FC3);
    alpha.convertTo(alpha, CV_32FC3, 1.0/255);

    multiply(alpha, foreground, foreground);
    multiply(cv::Scalar::all(1.0)-alpha, background, background);

    add(foreground, background, background);
}

void drawGradient(const cv::Scalar& color1, const cv::Scalar& color2, cv::Mat& image, double angle)
{
    const int rows = image.rows;
    const int cols = image.cols;
    image.create(rows, cols, CV_8UC3);

    const double radian = angle * CV_PI / 180.0;
    const double cosA = std::cos(radian);
    const double sinA = std::sin(radian);

    const double maxDistance = std::sqrt(rows * rows + cols * cols);

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            const double distance = (x * cosA + y * sinA);
            double alpha = distance / maxDistance;
            alpha = std::clamp(alpha, 0.0, 1.0);
            cv::Scalar color = (1.0 - alpha) * color1 + alpha * color2;
            image.at<cv::Vec3b>(y, x) = cv::Vec3b(color[0], color[1], color[2]);
        }
    }
}

int main()
{
    cv::Mat image(5320, 6960, CV_8UC3, cv::Scalar(10, 10, 10, 255));
    drawGradient(cv::Scalar(6, 19, 68), cv::Scalar(12, 42, 126), image, 45);

    StepFigure(RepeatingRow({
                   0
               }), {
                   2 * CV_PI * 4 / 9
               }, 9, CV_PI / 2 / 9)
        .draw(image, cv::Point(4000, 2500), 1200);

    StepFigure(RepeatingRow({
                   0
               }), {
                   2 * CV_PI * 4 / 15
               }, 15)
        .draw(image, cv::Point(3050, 500), 2000);

    StepFigure(RepeatingRow({
                   0
               }), {
                   2 * CV_PI * 47 / 120
               }, 120)
        .draw(image, cv::Point(1000, 3400), 4000);

    StepFigure(RepeatingRow({
                   0
               }), {
                   2 * CV_PI * 47 / 60
               }, 60)
        .draw(image, cv::Point(6000, 3000), 1500);

    StepFigure(RepeatingRow({
                   0
               }), {
                   2 * CV_PI * 2 / 5
               }, 5)
        .draw(image, cv::Point(6300, 1000), 1000);

    cv::Mat alpha = cv::Mat::zeros(image.rows, image.cols, CV_8UC3);
    StepFigure(RepeatingRow({
                   0
               }), {
                   2 * CV_PI * 101 / 240
               }, 240)
        .draw(alpha, cv::Point(4000, 5500), 10000);
    overlay(cv::Scalar(4, 137, 255), image, alpha, 0.5);

    StepFigure(RepeatingRow({
                   0
               }), {
                   2 * CV_PI * 6 / 20
               }, 20)
        .draw(image, cv::Point(5000, 700), 1000);

    if (!imwrite("result.jpg", image))
    {
        std::cerr << "Error saving the image" << std::endl;
        return -1;
    }

    std::cout << "Image saved as result.jpg" << std::endl;
    return 0;
}
