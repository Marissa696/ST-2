// Copyright 2024 Marina Saratova
#include <cstdint>
#include <stdexcept>
#include "circle.h"

Circle::Circle() {
    rad = 0.0;
    fer = 0.0;
    area = 0.0;
}

void Circle::calculatingArea() {
    area = PI * rad * rad;
}

void Circle::calculatingFerence() {
    fer = 2 * PI * rad;
}

Circle::Circle(double r) {
    if (r < 0) {
        throw std::invalid_argument("Радиус должен быть положительным");
    }
    rad = r;
    calculatingArea();
    calculatingFerence();
}

double Circle::getRad() {
    return rad;
}

double Circle::getFer() {
    return fer;
}

double Circle::getArea() {
    return area;
}


void Circle::setRad(double r) {
    if (r < 0) {
        throw std::invalid_argument("Радиус должен быть положительным");
    }
    rad = r;
    calculatingArea();
    calculatingFerence();
}

void Circle::setFer(double f) {
    if (f < 0) {
        throw std::invalid_argument
        ("Длина окружности должна быть положительной");
    }
    fer = f;
    rad = fer / (2 * PI);
    calculatingArea();
}

void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Площадь окружности должна
         быть положительной");
    }
    area = a;
    rad = sqrt(area / PI);
    calculatingFerence();
}
