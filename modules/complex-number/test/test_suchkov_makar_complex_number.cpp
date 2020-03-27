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

TEST(Suchkov_Makar_ComplexNumberTest, Check_Inverse_Element_Property) {
    // Arrange
    double re = 123.0;
    double im = 456.0;
    ComplexNumber pos(re, im);
    ComplexNumber neg(-re, -im);

    // Act
    ComplexNumber check = pos + neg;

    // Assert
    EXPECT_EQ(check.getRe(), 0.0);
    EXPECT_EQ(check.getIm(), 0.0);
}

TEST(Suchkov_Makar_ComplexNumberTest, Check_Correct_Use_Several_Math_Operations_In_One_String) {
    // Arrange
    double num1 = 10.0;
    double num2 = 5.0;
    double num3 = 3.0;
    double num4 = 2.0;
    double check = 0;

    ComplexNumber z1(num1, num1);
    ComplexNumber z2(num2, num2);
    ComplexNumber z3(num3, num3);
    ComplexNumber z4(num4, num4);
    ComplexNumber cCheck(0.0, 0.0);

    // Act
    check = num1 + num2 / num3 * num4;
    cCheck = z1 + z2 / z3 * z4;

    // Assert
    EXPECT_EQ(check, cCheck.getRe());
    EXPECT_EQ(check, cCheck.getIm());
}
