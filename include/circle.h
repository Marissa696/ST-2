// Copyright 2024 Marina Saratova
#pragma once
#include <cstdint>
#include <cmath>

class Circle {
 private:
    const double PI = 3.1415;
    double rad;
    double fer;
    double area;

 private:
    void calculatingFerence();
    void calculatingArea();

 public:
    Circle();
    explicit Circle(double rad);

    double getArea();
    double getRad();
    double getFerence();

    void setArea(double a);
    void setFer(double f);
    void setRad(double r);
};
