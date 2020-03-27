// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Suchkov_Makar_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}


TEST(Suchkov_Makar_ComplexNumberTest, Can_Get_Re) {
    // Arrange
    double re = 987.0;
    double im = 789.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
}

TEST(Suchkov_Makar_ComplexNumberTest, Can_Get_Im) {
    // Arrange
    double re = 2.0;
    double im = 3.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Suchkov_Makar_ComplexNumberTest, Multiple_By_Zero) {
    // Arrange
    double re = 123.0;
    double im = 987.0;
    ComplexNumber z(re, im);
    ComplexNumber zero(0.0, 0.0);

    // Act
    z = z * zero;

    // Assert
    EXPECT_EQ(z.getRe(), 0.0);
    EXPECT_EQ(z.getIm(), 0.0);
}

TEST(Suchkov_Makar_ComplexNumberTest, Negative_Number_Less_Than_Positive) {
    // Arrange
    double re1 = 555.0;
    double re2 = -555.0;
    double im1 = 777.0;
    double im2 = -777.0;

    // Act
    ComplexNumber pos(re1, im1);
    ComplexNumber neg(re2, im2);

    // Assert
    EXPECT_LT(neg.getRe(), pos.getRe());
    EXPECT_LT(neg.getIm(), pos.getIm());
}

TEST(Suchkov_Makar_ComplexNumberTest, Can_Add_Complex_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 4.0;
    double im2 = -5.0;

    double re3 = 5.0;
    double im3 = -7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 + z2, z3);
}

TEST(Suchkov_Makar_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    // Arrange
    double re1 = -3.0;
    double im1 = 6.0;

    double re2 = 2.0;
    double im2 = 7.0;

    double re3 = -5.0;
    double im3 = -1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 - z2, z3);
}


TEST(Suchkov_Makar_ComplexNumberTest, Can_Divide_Complex_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = -1.0;

    double re2 = 1.0;
    double im2 = 1.0;

    double re3 = 0.0;
    double im3 = -1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 / z2, z3);
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Multiply_Complex_Numbers) {
    // Arrange
    double re1 = 2.0;
    double im1 = 4.0;

    double re2 = -4.0;
    double im2 = 5.0;

    double re3 = -28.0;
    double im3 = -6.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 * z2, z3);
}

TEST(Suchkov_Makar_ComplexNumberTest, Correct_Copy_Constructor) {
    // Arrange
    double re1 = 2.0;
    double im1 = 1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(z1, z2);
}