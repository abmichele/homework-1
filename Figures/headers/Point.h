#pragma once

#include <ostream>


class Point {

public:

    Point(double x, double y);
    void operator=(const Point& point);
    friend std::ostream& operator<<(std::ostream& stream, const Point& point);

    bool operator!=(const Point& point) const;

public:
    double x_;
    double y_;
};

