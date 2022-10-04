#include "../headers/Point.h"

#include <string>

Point::Point(double x, double y)
    : x_(x), y_(y)
{
}

void Point::operator=(const Point& point)
{
    this->x_ = point.x_;
    this->y_ = point.y_;
}

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
    stream << "(" << std::to_string(point.x_) << "; " << std::to_string(point.y_) << ")";
    return stream;
}

bool Point::operator!=(const Point& point) const
{
    return x_ != point.x_ || y_ != point.y_;
}
