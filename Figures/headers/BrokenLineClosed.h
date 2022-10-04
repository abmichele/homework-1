#pragma once

#include "Point.h" // подключаем класс Точка
#include "BrokenLine.h" // Подключаем класс Ломаная

#include <vector> // для использования структуры "вектор"



class BrokenLineClosed : public BrokenLine
{
public:


    BrokenLineClosed(const BrokenLineClosed& broken_line);

    BrokenLineClosed(const std::vector<Point>& points);


    BrokenLineClosed(const std::vector<std::pair<double, double>>& points);
    BrokenLineClosed& operator=(const BrokenLineClosed& broken_line);
    Point& operator[](size_t index);


    const Point& operator[](size_t index) const;

    double getLength() const override;
};
