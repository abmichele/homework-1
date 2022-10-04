#pragma once

#include "Point.h"

#include <vector>

class BrokenLine
{
public:
    BrokenLine(const BrokenLine& broken_line);

    BrokenLine(std::vector<Point> points);

    BrokenLine(const std::vector<std::pair<double, double>>& points);

    BrokenLine& operator=(const BrokenLine& broken_line);

    virtual double getLength() const;

    Point& operator[](size_t index);


    const Point& operator[](size_t index) const;


    size_t getPointsNumber() const;

protected:

    std::vector<Point> getPoints() const;
    void setPoints(std::vector<Point>&& points);

    void setPoints(const BrokenLine& broken_line);

    std::vector<Point> points_;
};
