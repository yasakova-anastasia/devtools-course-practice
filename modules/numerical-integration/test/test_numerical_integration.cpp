// Copyright 2020 Boganov Sergei

#define _USE_MATH_DEFINES

#include <gtest/gtest.h>

#include <cmath>

#include "include/numerical_integration.h"

class NumericalIntegrationTest : public NumericalIntegration {
public:
    static const double epsilon;
    static const unsigned int N;

    static double f1(double x)
    {
        return x * x;
    }
    static double F1(double x)
    {
        return (x * x * x) / 3.0;
    }

    static double f2(double x)
    {
        return 1.0 - x;
    }
    static double F2(double x)
    {
        return x - (x * x) / 2.0;
    }

    static double f3(double x)
    {
        return cos(x);
    }
    static double F3(double x)
    {
        return sin(x);
    }
};

const double NumericalIntegrationTest::epsilon = 0.001;
const unsigned int NumericalIntegrationTest::N = 100000;

TEST(NumericalIntegrationTest, Can_Create_Correct_Object) {
    // Arrange
    double a = 0.0;
    double b = 1.0;
    double x = 3.0;

    // Act
    NumericalIntegration obj(a, b, NumericalIntegrationTest::f1);

    // Assert
    EXPECT_EQ(a, obj.a);
    EXPECT_EQ(b, obj.b);
    EXPECT_EQ(NumericalIntegrationTest::f1(x), obj.f(x));
}

TEST(NumericalIntegrationTest, TestLeftRectangleMethod) {
    // Arrange
    double a = 0.0;
    double b = 3.0;
    double ans = NumericalIntegrationTest::F1(b) - NumericalIntegrationTest::F1(a);

    // Act
    NumericalIntegration obj(a, b, NumericalIntegrationTest::f1);

    // Assert
    EXPECT_NEAR(ans, obj.Left_rectangle_method(NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestRightRectangleMethod) {
    // Arrange
    double a = M_PI / 4.0;
    double b = M_PI / 2.0;
    double ans = NumericalIntegrationTest::F3(b) - NumericalIntegrationTest::F3(a);

    // Act
    NumericalIntegration obj(a, b, NumericalIntegrationTest::f3);

    // Assert
    EXPECT_NEAR(ans, obj.Right_rectangle_method(NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestMiddleRectangleMethod) {
    // Arrange
    double a = 2.0;
    double b = 4.0;
    double ans = NumericalIntegrationTest::F2(b) - NumericalIntegrationTest::F2(a);

    // Act
    NumericalIntegration obj(a, b, NumericalIntegrationTest::f2);

    // Assert
    EXPECT_NEAR(ans, obj.Middle_rectangle_method(NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestTrapezoidMethod) {
    // Arrange
    double a = -1.0;
    double b = 5.0;
    double ans = NumericalIntegrationTest::F1(b) - NumericalIntegrationTest::F1(a);

    // Act
    NumericalIntegration obj(a, b, NumericalIntegrationTest::f1);

    // Assert
    EXPECT_NEAR(ans, obj.Trapezoid_method(NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestSimpsonsMethod) {
    // Arrange
    double a = 4.0;
    double b = 7.0;
    double ans = NumericalIntegrationTest::F2(b) - NumericalIntegrationTest::F2(a);

    // Act
    NumericalIntegration obj(a, b, NumericalIntegrationTest::f2);

    // Assert
    EXPECT_NEAR(ans, obj.Simpsons_method(NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}

TEST(NumericalIntegrationTest, TestGaussMethod) {
    // Arrange
    double a = M_PI / 6.0;
    double b = M_PI / 3.0;
    double ans = NumericalIntegrationTest::F3(b) - NumericalIntegrationTest::F3(a);

    // Act
    NumericalIntegration obj(a, b, NumericalIntegrationTest::f3);

    // Assert
    EXPECT_NEAR(ans, obj.Gauss_method(NumericalIntegrationTest::N), NumericalIntegrationTest::epsilon);
}
