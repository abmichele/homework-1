#include "../headers/Triangle.h"

#include <stdexcept>

Triangle::Triangle(const std::vector<Point>& points)
    : PolygonalFigure(points)
{
    is3Sides();
}

Triangle::Triangle(const Triangle& triangle) = default;

Triangle::Triangle(const std::vector<std::pair<double, double>>& points)
    : PolygonalFigure(points)
{

    is3Sides();
}

Triangle& Triangle::operator=(const Triangle& triangle)
{
    setPoints(triangle);
    return *this;
}

void Triangle::is3Sides() const
{
    if (this->getPointsNumber() != 3)
    {
        throw std::logic_error("This isn't a triangle! Must be 3 sides (3 points).");
    }
}
