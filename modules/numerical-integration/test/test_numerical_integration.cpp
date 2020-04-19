// Copyright 2020 Boganov Sergei

#include <gtest/gtest.h>

#include <cmath>

#include "include/numerical_integration.h"

class NumericalIntegrationTest : public NumericalIntegration {
public:
    double epsilon = 0.001;
    static double f1(double x)
    {
        return x * x;
    }
    static double f2(double x)
    {
        return 1.0 - x;
    }
    static double f3(double x)
    {
        return cos(x);
    }
};

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