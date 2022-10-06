#pragma once

#include "BrokenLineClosed.h"


class PolygonalFigure : protected BrokenLineClosed
{
public:
    PolygonalFigure(const PolygonalFigure& polygonal_figure);
    PolygonalFigure(const std::vector<Point>& points);
    PolygonalFigure(const std::vector<std::pair<double, double>>& points);

    double getPerimeter() const;

    double getArea() const;

    PolygonalFigure& operator=(const PolygonalFigure& polygonal_figure);

    virtual bool isCorrectFigure();
protected:
    bool isEqualCorners();
    bool isEqualSides();
};


