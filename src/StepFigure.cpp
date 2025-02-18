//
// Created by yorick on 10 Feb 2025.
//

#include "../include/StepFigure.h"

#include <opencv2/imgproc.hpp>

StepFigure::StepFigure(const Row& row, const std::vector<double>& angles, const int steps,  const double startDirection):
    _angles(angles),
    _steps(steps),
    _startDirection(startDirection),
    _row(*row.clone())
{
    double min_x = 0, max_x = 0;
    double min_y = 0, max_y = 0;

    double currentDirection = this->_startDirection;
    cv::Point2d currentPoint(0, 0);

    for (int i = 0; i < _steps; i++)
    {
        currentPoint = this->_nextPoint(currentPoint, currentDirection, 1);
        min_x = std::min(min_x, currentPoint.x);
        max_x = std::max(max_x, currentPoint.x);
        min_y = std::min(min_y, currentPoint.y);
        max_y = std::max(max_y, currentPoint.y);
    }
    this->_center = cv::Point2d((min_x + max_x) / 2, (min_y + max_y) / 2);
}

void StepFigure::draw(cv::Mat& img, const cv::Point2d startingPoint, const double stepLength) const
{
    double currentDirection =this->_startDirection;
    cv::Point2d currentPoint = startingPoint - this->_center * stepLength;

    for (int i = 0; i < _steps; i++)
    {
        cv::Point2d newPoint = this->_nextPoint(currentPoint, currentDirection, stepLength);

        line(img, currentPoint, newPoint, cv::Scalar(255, 255, 255), 2);

        swap(currentPoint, newPoint);
    }
}

cv::Point2d StepFigure::_nextPoint(const cv::Point2d& currentPoint, double& currentDirection, const double stepLength) const
{
    const int step = this->_row.next();
    currentDirection += _angles[step];
    return cv::Point2d(
        currentPoint.x + stepLength * std::cos(currentDirection),
        currentPoint.y + stepLength * std::sin(currentDirection)
    );
}
