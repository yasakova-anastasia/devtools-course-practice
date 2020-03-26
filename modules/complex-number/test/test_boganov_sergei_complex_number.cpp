// Copyright 2020 Boganov Sergei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Boganov_Sergei_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Get_Re) {
    // Arrange
    double re = 5.0;
    double im = 1.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Get_Im) {
    // Arrange
    double re = 2.0;
    double im = 3.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(im, z.getIm());
}

TEST(Boganov_Sergei_ComplexNumberTest, Correct_Assignment_Operator) {
    // Arrange
    double re1 = 2.0;
    double im1 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2;

    z2 = z1;

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Set_Re) {
    // Arrange
    double re1 = 2.0;
    double im1 = 3.0;

    double re2 = -5.0;

    // Act
    ComplexNumber z(re1, im1);

    z.setRe(re2);

    // Assert
    EXPECT_EQ(re2, z.getRe());
}