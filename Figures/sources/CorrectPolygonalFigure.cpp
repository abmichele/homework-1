#include "../headers/CorrectPolygonalFigure.h"

CorrectPolygonalFigure::CorrectPolygonalFigure(const std::vector<Point>& points)
    : PolygonalFigure(points)
{
    isCorrectFigure();
}

CorrectPolygonalFigure::CorrectPolygonalFigure(const std::vector<std::pair<double, double>>& points)
    : PolygonalFigure(points)
{
    isCorrectFigure();
}


CorrectPolygonalFigure::CorrectPolygonalFigure(const CorrectPolygonalFigure& correct_polygonal_figure) = default;

CorrectPolygonalFigure& CorrectPolygonalFigure::operator=(const CorrectPolygonalFigure& correct_polygonal_figure)
{
    setPoints(correct_polygonal_figure);

    return *this;
}

bool CorrectPolygonalFigure::isCorrectFigure()
{
    if (isEqualSides() && isEqualCorners())
        return true;
    throw std::logic_error("Wrong input parametrs! This isn't correct polygonal figure.");
}
