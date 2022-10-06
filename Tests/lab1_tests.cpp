#include "../Figures/headers/BrokenLineClosed.h"
#include "../Figures/headers/Point.h"
#include "../Figures/headers/PolygonalFigure.h"
#include "../Figures/headers/BrokenLine.h"
#include "../Figures/headers/CorrectPolygonalFigure.h"
#include "../Figures/headers/Trapeze.h"
#include "../Figures/headers/Triangle.h"

#include <cmath>
#include <gtest/gtest.h>
#include <vector>

TEST(CreateBrokenLine, PerimeterCalculatedCorrectly)
{
    std::vector<Point> points = {{1, 1}, {1, 2}, {2, 2}, {2, 5}, {9, 5}};
    BrokenLine broken_line(points);
    ASSERT_EQ(broken_line.getLength(), 12);

    std::vector<Point> points2 = {{-1, -1}, {0, 0}, {0, 2}, {-7, 2}, {-5, 0}};
    BrokenLine broken_line2(points2);
    ASSERT_EQ(broken_line2.getLength(), 9 + 3 * sqrt(2));
}

TEST(CreateEmptyPolygonalChain, IsZeroPerimeter)
{
    std::vector<Point> points = {};
    BrokenLine broken_line(points);
    ASSERT_EQ(broken_line.getLength(), 0);
}

TEST(CreatePolygonalFigure, PerimeterAndAreaCalculatedCorrectly)
{
    std::vector<Point> points = {{1, 1}, {1, 2}, {2, 2}, {2, 1}};
    PolygonalFigure polygonal_figure(points);
    ASSERT_EQ(polygonal_figure.getPerimeter(), 4);
    ASSERT_EQ(polygonal_figure.getArea(), 1);

    std::vector<Point> points2 = {{2, 1}, {1, 2}, {2, 3}, {3, 2}};
    PolygonalFigure polygonal_figure2(points2);
    ASSERT_EQ(polygonal_figure2.getPerimeter(), 4 * sqrt(2));
    ASSERT_EQ(polygonal_figure2.getArea(), 2);

    std::vector<Point> points3 = {{1, 1}, {1, 2}, {0, 2}, {0, 3}, {1, 3}, {1, 4}, {2, 4}, {2, 3}, {3, 3}, {3, 2}, {2, 2}, {2, 1}};
    PolygonalFigure polygonal_figure3(points3);
    ASSERT_EQ(polygonal_figure3.getPerimeter(), 12);
    ASSERT_EQ(polygonal_figure3.getArea(), 5);
}


TEST(CreateTrapeze, PerimeterAndAreaCalculatedCorrectly)
{
    std::vector<Point> points = {{0, 0}, {2, 2}, {4, 2}, {6, 0}};
    Trapeze trapeze(points);
    ASSERT_EQ(trapeze.getPerimeter(), 8 + 4 * sqrt(2));
    ASSERT_EQ(trapeze.getArea(), 8);
}

TEST(CreateSquare, RightRectangleCheckPassed)
{
    std::vector<Point> points = {{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    PolygonalFigure square(points);
    ASSERT_NO_THROW(square.isCorrectFigure());
}

TEST(CreateTriangle, PerimeterAndAreaCalculatedCorrectly)
{
    std::vector<Point> points = {{0, 0}, {4, 3}, {8, 0}};
    Triangle triangle(points);
    ASSERT_EQ(triangle.getPerimeter(), 18);
    ASSERT_EQ(triangle.getArea(), 12);
}

TEST(TryToCreateSquareAsTrapeze, TrapezoidCheckFailed_ThrowException)
{
    std::vector<Point> points = {{0, 0}, {0, 2}, {2, 2}, {2, 0}};
    ASSERT_THROW(Trapeze trapeze(points), std::logic_error);
}

TEST(CreateCorrectPolygonalFigure, CorrectlyCheckPassed)
{
    std::vector<Point> points = {{0, 0}, {-1, 1}, {0, 2}, {1, 1}};
    ASSERT_NO_THROW(CorrectPolygonalFigure square(points));
}

TEST(CreateRectangle, CorrectlyCheckFailed_ThrowException)
{
    std::vector<Point> points = {{-5, 0}, {-1, 1}, {0, 7}, {1, 1}};
    ASSERT_THROW(CorrectPolygonalFigure rectangle(points), std::logic_error);
}

TEST(CreateRhomb, CorrectlyCheckFailed_ThrowException)
{
    std::vector<Point> points = {{0, 0}, {-2, 5}, {0, 10}, {2, 5}};
    ASSERT_THROW(CorrectPolygonalFigure rhomb(points), std::logic_error);
}
