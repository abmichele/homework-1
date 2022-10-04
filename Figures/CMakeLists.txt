cmake_minimum_required(VERSION 3.13)

# имя прокета - Figures, язык С++
project(Figures LANGUAGES CXX)

# установить директорию с заголовочными файлами *.h
set(HEADERS_DIR "headers")

# установить директорию с исходными файлами *.cpp
set(SOURCES_DIR "sources")

# установить список заголовочных файлов
set(
    HEADERS
    "${HEADERS_DIR}/Point.h"
    "${HEADERS_DIR}/BrokenLine.h"
    "${HEADERS_DIR}/BrokenLineClosed.h"
    "${HEADERS_DIR}/PolygonalFigure.h"
    "${HEADERS_DIR}/CorrectPolygonalFigure.h"
    "${HEADERS_DIR}/Trapeze.h"
    "${HEADERS_DIR}/Triangle.h"
)

# установить список исходников
set(
    SOURCES
    "${SOURCES_DIR}/Point.cpp"
    "${SOURCES_DIR}/BrokenLine.cpp"
    "${SOURCES_DIR}/BrokenLineClosed.cpp"
    "${SOURCES_DIR}/PolygonalFigure.cpp"
    "${SOURCES_DIR}/CorrectPolygonalFigure.cpp"
    "${SOURCES_DIR}/Trapeze.cpp"
    "${SOURCES_DIR}/Triangle.cpp"
)

# зарегистрировать файлы
add_library(
    ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)

