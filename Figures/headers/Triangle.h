#pragma once

#include "Point.h" // подключаем класс Точка
#include "PolygonalFigure.h" // Подключаем класс Многоугольник


class Triangle : public PolygonalFigure
{
public:
    Triangle(const Triangle& triangle);
    Triangle(const std::vector<Point>& points);
    Triangle(const std::vector<std::pair<double, double>>& points);
    Triangle& operator=(const Triangle& Triangle);

private:
    void is3Sides() const;
};


