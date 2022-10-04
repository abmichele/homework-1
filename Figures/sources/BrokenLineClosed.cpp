#include "../headers/BrokenLineClosed.h"

#include <cmath>

BrokenLineClosed::BrokenLineClosed(const std::vector<Point>& points)
    : BrokenLine(points)
{

}

BrokenLineClosed::BrokenLineClosed(const std::vector<std::pair<double, double>>& points)
    : BrokenLine(points)
{

}

BrokenLineClosed& BrokenLineClosed::operator=(const BrokenLineClosed& broken_line)
{
    this->setPoints(broken_line);
    return *this;
}

Point& BrokenLineClosed::operator[](size_t index)
{
    return points_[index];
}

const Point& BrokenLineClosed::operator[](size_t index) const
{
    return points_[index];
}


BrokenLineClosed::BrokenLineClosed(const BrokenLineClosed& broken_line) = default;

double BrokenLineClosed::getLength() const
{
    size_t last = this->getPointsNumber() - 1;

    auto side_A = std::pow(((*this)[0].x_ - (*this)[last].x_), 2);
    auto side_B = std::pow(((*this)[0].y_ - (*this)[last].y_), 2);

    return BrokenLine::getLength() + std::sqrt(side_A + side_B);
}
