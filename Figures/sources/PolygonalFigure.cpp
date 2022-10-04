#include "../headers/PolygonalFigure.h"

#include <stdexcept>
#include <cmath>


double PolygonalFigure::getArea() const
{
    double area = 0;
    PolygonalFigure figure = *this;
    size_t size = figure.getPointsNumber();
    for (size_t i = 0; i < size - 1; ++i)
    {
        auto X1 = figure[i].x_; auto X2 = figure[i+1].x_;
        auto Y1 = figure[i].y_; auto Y2 = figure[i+1].y_;

        // сумма от i по n: (X_i + X_(i+1)) * (Y_i - Y_(i+1))
        area += ((X1 + X2) * (Y1 - Y2));
    }


    auto X1 = figure[size-1].x_; auto X2 = figure[0].x_;
    auto Y1 = figure[size-1].y_; auto Y2 = figure[0].y_;

    area += ((X1 + X2) * (Y1 - Y2));

    area = 0.5 * std::abs(area);
    return area;
}


PolygonalFigure::PolygonalFigure(const PolygonalFigure& polygonal_figure) = default;

PolygonalFigure::PolygonalFigure(const std::vector<Point>& points)
    : BrokenLineClosed(points)
{

}

PolygonalFigure::PolygonalFigure(const std::vector<std::pair<double, double>>& points)
    : BrokenLineClosed(points)
{

}

PolygonalFigure& PolygonalFigure::operator=(const PolygonalFigure& polygonal_figure)
{
    this->setPoints(polygonal_figure);

    return *this;
}

bool PolygonalFigure::isCorrectFigure()
{
    if (isEqualSides() && isEqualCorners())
        return true;

    return false;

}

bool PolygonalFigure::isEqualCorners()
{
    PolygonalFigure figure = *this;

    size_t size = figure.getPointsNumber();

    auto X = figure[size-2].x_ - figure[0].x_;
    auto Y = figure[size-2].y_ - figure[0].y_;
    auto side = std::pow(X, 2) + std::pow(Y, 2);
    for (size_t i = 2; i < size; ++i)
    {
        X = figure[i-2].x_ - figure[i].x_;
        Y = figure[i-2].y_ - figure[i].y_;
        auto side_i = std::pow(X, 2) + std::pow(Y, 2);

        if (side_i != side)
            return false;
    }

    X = figure[size-1].x_ - figure[1].x_;
    Y = figure[size-1].y_ - figure[1].y_;
    auto side_last = std::pow(X, 2) + std::pow(Y, 2);

    if (side_last != side)
        return false;

    return true;
}

bool PolygonalFigure::isEqualSides()
{
    PolygonalFigure figure = *this;
    size_t size = figure.getPointsNumber();

    auto X = figure[size-1].x_ - figure[0].x_;
    auto Y = figure[size-1].y_ - figure[0].y_;
    auto side_length = std::pow(X, 2) + std::pow(Y, 2);


    for (size_t i = 0; i < size - 1; ++i)
    {
        X = figure[i+1].x_ - figure[i].x_;
        Y = figure[i+1].y_ - figure[i].y_;

        auto another_side_len = std::pow(X, 2) + std::pow(Y, 2);

        if (another_side_len != side_length)
            return false;
    }


    return true;
}


double PolygonalFigure::getPerimeter() const
{
    return this->getLength();
}
