#include "../headers/BrokenLine.h"

#include <cmath>

BrokenLine::BrokenLine(std::vector<Point> points)
    : points_(std::move(points)) {
}

BrokenLine::BrokenLine(const std::vector<std::pair<double, double>>& points) {
    for (const auto& point: points)
    {
        Point new_point(point.first, point.second);
        points_.push_back(new_point);
    }
}

double BrokenLine::getLength() const
{
    double length = 0;

    for (size_t i = 1; i < points_.size(); ++i)
    {
        double line =
                std::sqrt(
                    (points_[i].x_ - points_[i - 1].x_) * (points_[i].x_ - points_[i - 1].x_) +
                (points_[i].y_ - points_[i - 1].y_) * (points_[i].y_ - points_[i - 1].y_));
        length += line;
    }

    return length;
}

Point& BrokenLine::operator[](size_t index)
{
    return points_[index];
}

const Point& BrokenLine::operator[](size_t index) const
{
    return points_[index];
}

size_t BrokenLine::getPointsNumber() const
{
    return points_.size();
}

std::vector<Point> BrokenLine::getPoints() const
{
    return points_;
}
BrokenLine::BrokenLine(const BrokenLine& broken_line) = default;

void BrokenLine::setPoints(std::vector<Point>&& points)
{
    points_ = points;
}

void BrokenLine::setPoints(const BrokenLine& broken_line)
{
    this->points_ = broken_line.points_;
}
