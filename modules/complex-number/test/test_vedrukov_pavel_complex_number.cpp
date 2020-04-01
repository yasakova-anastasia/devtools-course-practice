// Copyright 2020 Vedrukov Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vedrukov_Pavel_Complex_Number_Test_1, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
