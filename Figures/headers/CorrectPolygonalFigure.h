#pragma once

#include "PolygonalFigure.h"


class CorrectPolygonalFigure : PolygonalFigure
{
public:

    CorrectPolygonalFigure(const CorrectPolygonalFigure& correct_polygonal_figure);
    CorrectPolygonalFigure(const std::vector<Point>& points);

    CorrectPolygonalFigure(const std::vector<std::pair<double, double>>& points);

    CorrectPolygonalFigure& operator=(const CorrectPolygonalFigure& correct_polygonal_figure);


    bool isCorrectFigure() override;
};


