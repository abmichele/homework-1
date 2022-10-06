#include "../headers/Trapeze.h"

#include <stdexcept>

Trapeze::Trapeze(const std::vector<Point>& points)
    : PolygonalFigure(points)
{
    isTrapeze();
}

Trapeze::Trapeze(const std::vector<std::pair<double, double>>& points)
    : PolygonalFigure(points)
{
    isTrapeze();
}

Trapeze& Trapeze::operator=(const Trapeze& trapeze)
{
    this->setPoints(trapeze);
    return *this;
}

void Trapeze::is4Sides() const
{
    if (this->getPointsNumber() != 4)
    {
        throw std::logic_error("This isn't a trapeze! Must be 4 sides (4 points).");
    }
}


Trapeze::Trapeze(const Trapeze& trapeze) = default;

void Trapeze::parallelismProperty() const
{
    Trapeze figure = *this;

    auto x1 = figure[0].x_, x2 = figure[1].x_, x3 = figure[2].x_, x4 = figure[3].x_;
    auto y1 = figure[0].y_, y2 = figure[1].y_, y3 = figure[2].y_, y4 = figure[3].y_;

    if (
            !((
                ((x2 - x1) * (y4 - y3) != (x4 - x3) * (y2 - y1)) &&
                ((x2 - x3) * (y4 - y1) == (x4 - x1) * (y2 - y3))
                ) ||
            (
                ((x2 - x3) * (y4 - y1) != (x4 - x1) * (y2 - y3)) &&
                ((x2 - x1) * (y4 - y3) == (x4 - x3) * (y2 - y1))
            ))
        )
    {
        throw std::logic_error("Trapeze must have two parallel and two not parallel lines!");
    }
}

void Trapeze::isTrapeze() const
{
    is4Sides();
    parallelismProperty();
}
