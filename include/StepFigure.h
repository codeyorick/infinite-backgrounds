//
// Created by yorick on 10 Feb 2025.
//

#ifndef STEPFIGURE_H
#define STEPFIGURE_H

#include <vector>
#include <opencv2/core/mat.hpp>

#include "Row.h"

class StepFigure
{
public:
    StepFigure(const Row& row, const std::vector<double>& angles, int steps, double startDirection = 0);
    void draw(cv::Mat& img, cv::Point2d startingPoint, double stepLength) const;
private:
    const std::vector<double> _angles;
    const int _steps;
    const double _startDirection;

    Row& _row;
    cv::Point2d _center;

    cv::Point2d _nextPoint(const cv::Point2d& currentPoint, double& currentDirection, double stepLength) const;
};

#endif //STEPFIGURE_H
