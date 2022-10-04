#pragma once

#include "PolygonalFigure.h"

class Trapeze : public PolygonalFigure
{
public:
    Trapeze(const Trapeze& trapeze);
    Trapeze(const std::vector<Point>& points);
    Trapeze(const std::vector<std::pair<double, double>>& points);
    Trapeze& operator=(const Trapeze& trapeze);

private:
    void is4Sides() const;
    void isTrapeze() const;
    void parallelismProperty() const;
};
