// Copyright 2020 Tanskii Yurii

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Tanskii_Yurii_ComplexNumberTest, Can_Multi) {
    // Arrange
    double re1 = 7.0;
    double im1 = 3.0;
    double re2 = 5.0;
    double im2 = -8.0;
    double ans_re = 59.0;
    double ans_im = -41.0;


    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(0.0, 0.0);
    z3 = z1 * z2;

    // Assert
    EXPECT_EQ(ans_re, z3.getRe());
    EXPECT_EQ(ans_im, z3.getIm());

}