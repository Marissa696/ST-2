// Copyright 2024 Fedor Khodyrev

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

double EPS = 1e-5;
TEST(Marina_Saratova_Test_Circle, test_circle_setter) {
    Circle circle1;
    circle1.setRad(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getRad(), 1000.0);
}

TEST(Marina_Saratova_Test_Circle, test_circle_constructor_with_radius) {
    Circle circle1(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getRad(), 1000.0);
}

TEST(Marina_Saratova_Test_Circle, test_circle_constructor) {
    Circle circle1;
    EXPECT_DOUBLE_EQ(circle1.getRad(), 0.0);
}

TEST(Marina_Saratova_Test_Circle, test_ference_autoset) {
    Circle circle1(6378.1);
    EXPECT_DOUBLE_EQ(circle1.getFer(), 40074.750357999998);
}

TEST(Marina_Saratova_Test_Circle, test_area_autoset) {
    Circle circle1(6378.1);
    EXPECT_DOUBLE_EQ(circle1.getArea(), 127800382.62917989);
}

TEST(Marina_Saratova_Test_Circle, test_setter_ference) {
    Circle circle1;
    circle1.setFer(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getFer(), 1000.0);
}

TEST(Marina_Saratova_Test_Circle, test_setter_area) {
    Circle circle1;
    circle1.setArea(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getArea(), 1000.0);
}

TEST(Marina_Saratova_Test_Circle, test_ference_changed_after_area) {
    Circle circle1;
    circle1.setArea(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getFer(), 112.09977698461313);
}

TEST(Marina_Saratova_Test_Circle, test_ference_changed_after_radius) {
    Circle circle1;
    circle1.setRad(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getFer(), 6283.18);
}

TEST(Marina_Saratova_Test_Circle, test_area_changed_after_radius) {
    Circle circle1;
    circle1.setRad(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getArea(), 3141589.9999999995);
}

TEST(Marina_Saratova_Test_Circle, test_radius_changed_after_ference) {
    Circle circle1;
    circle1.setFer(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getRad(), 159.15507752443827);
}

TEST(Marina_Saratova_Test_Circle, test_radius_changed_after_area) {
    Circle circle1;
    circle1.setArea(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getRad(), 17.841248696458344);
}

TEST(Marina_Saratova_Test_Circle, test_area_changed_after_ference) {
    Circle circle1;
    circle1.setFer(1000.0);
    EXPECT_DOUBLE_EQ(circle1.getArea(), 79577.538762219134);
}

TEST(Marina_Saratova_Test_Circle, test_set_negative_radius) {
    Circle circle1;
    ASSERT_ANY_THROW(circle1.setRad(-1000.0));
    ASSERT_ANY_THROW(circle1.setRad(-2000.0));
    ASSERT_ANY_THROW(circle1.setRad(-3000.0));
}

TEST(Marina_Saratova_Test_Circle, test_create_circle_with_negative_radius) {
    ASSERT_ANY_THROW(Circle circle1(-1000.0););
    ASSERT_ANY_THROW(Circle circle1(-2000.0););
    ASSERT_ANY_THROW(Circle circle1(-3000.0););
}

TEST(Marina_Saratova_Test_Circle, check_area_two_circles_with_equal_radius) {
    double radius = 10.2;
    Circle c1(radius), c2(radius);
    EXPECT_DOUBLE_EQ(c1.getArea(), c2.getArea());
}

TEST(Marina_Saratova_Test_Circle, test_set_negative_area) {
    Circle circle1;
    ASSERT_ANY_THROW(circle1.setArea(-1000.0));
    ASSERT_ANY_THROW(circle1.setArea(-2000.0));
    ASSERT_ANY_THROW(circle1.setArea(-3000.0));
}

TEST(Marina_Saratova_Test_Circle, test_set_negative_ference) {
    Circle circle1;
    ASSERT_ANY_THROW(circle1.setFer(-1000.0));
    ASSERT_ANY_THROW(circle1.setFer(-2000.0));
    ASSERT_ANY_THROW(circle1.setFer(-3000.0));
}

TEST(Marina_Saratova_Test_Circle, first_task) {
    double earthRadiusMeters = 6378.1 * 1000.0;
    double startRopeMeters = earthRadiusMeters * 2 * 3.14159;
    double actualResultMeters = (startRopeMeters + 1)
        / 2 / 3.14159 - earthRadiusMeters;
    double tolerance = 0.0001;
    ASSERT_NEAR(earthAndRopeTask(1.0), actualResultMeters, tolerance);
}

TEST(Marina_Saratova_Test_Circle, second_task) {
    double poolRadius = 3.0;
    double areaWidth = 1.0;

    double meterFencePrice = 2000;
    double squareMeterAreaPrice = 1000;

    double fencePrice = 2 * 3.14159 * (poolRadius + areaWidth) *
    meterFencePrice;
    double areaPrice = ((poolRadius + areaWidth) * (poolRadius +
    areaWidth) * 3.14159 -
        (poolRadius * poolRadius) * 3.14159) * squareMeterAreaPrice;

    ASSERT_DOUBLE_EQ(swimmingPoolTask(poolRadius, areaWidth,
        squareMeterAreaPrice, meterFencePrice), fencePrice + areaPrice);
}
