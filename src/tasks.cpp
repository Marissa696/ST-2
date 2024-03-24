// Copyright 2024 Marina Saratova
#include "tasks.h"
#include "circle.h"

double swimmingPoolTask(double swimmingPoolRadius, double conWidht,
    double conPrice, double fenPrice) {
    Circle swimmingPool(swimmingPoolRadius);
    Circle fullArea(swimmingPoolRadius + conWidht);
    double areaOfConcrete = fullArea.getArea() - swimmingPool.getArea();
    double priceForFence = fullArea.getFer() * fenPrice;
    return areaOfConcrete * conPrice + priceForFence;
}
double earthAndRopeTask(double extraLength) {
    double earthRadius = 6378.1;
    Circle earth(earthRadius);
    double firstRopeLength = earth.getFer();
    double secondRopeLength = (firstRopeLength * 1000.0 + 1.0) / 1000.0;
    Circle sphere;
    sphere.setFer(secondRopeLength);
    return (sphere.getRad() - earth.getRad()) * 1000.0;
}
