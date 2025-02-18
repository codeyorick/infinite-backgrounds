#include <iostream>
#include <opencv2/opencv.hpp>

#include "../include/RepeatingRow.h"
#include "../include/Row.h"
#include "../include/StepFigure.h"

void overlay(cv::Mat& image, cv::Mat& mask, const cv::Vec4b color)
{
    const uchar alpha = color[3];
    const cv::Vec3b colorNoAlpha(color[0], color[1], color[2]);


    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            const uchar pointAlpha = alpha * mask.at<uchar>(i, j) / 255;
            image.at<cv::Vec3b>(i, j) = (image.at<cv::Vec3b>(i, j) * (255 - pointAlpha) / 255 + colorNoAlpha * pointAlpha / 255);
        }
    }
};

int main()
{
    cv::Mat image(5320, 6960, CV_8UC4, cv::Scalar(10, 10, 10, 255));

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

    //cv::Mat figure = cv::Mat::zeros(image.rows, image.cols, CV_8UC1);
    StepFigure(RepeatingRow({
                   0
               }), {
                   2 * CV_PI * 101 / 240
               }, 240)
        .draw(image, cv::Point(4000, 5500), 10000);
    //overlay(image, figure, cv::Scalar(255, 255, 0, 200));

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
