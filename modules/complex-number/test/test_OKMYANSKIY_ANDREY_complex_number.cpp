// Copyright 2020 Okmyanskiy Andrey

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Okmyanskiy_Andrey_ComplexNumberTest, Multiply_Complex_And_Zero) {
    // Arrange
    double re = 15.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    ComplexNumber complexZero(0.0, 0.0);
    ComplexNumber testZero;

    // Act
    testZero = z * complexZero;

    // Assert
    EXPECT_EQ(complexZero, testZero);
}

TEST(Okmyanskiy_Andrey_ComplexNumberTest, Addition_Complex_And_Zero) {
    // Arrange
    double re = 15.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    ComplexNumber complexZero(0.0, 0.0);
    ComplexNumber testZero;

    // Act
    testZero = z + complexZero;

    // Assert
    EXPECT_EQ(z, testZero);
}

TEST(Okmyanskiy_Andrey_ComplexNumberTest, Difference_Complex_And_Zero) {
    // Arrange
    double re = 15.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    ComplexNumber complexZero(0.0, 0.0);
    ComplexNumber testZero;

    // Act
    testZero = z - complexZero;

    // Assert
    EXPECT_EQ(z, testZero);
}

TEST(Okmyanskiy_Andrey_ComplexNumberTest, Division_Complex_And_Zero) {
    // Arrange
    double re = 15.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    ComplexNumber complexZero(0.0, 0.0);
    ComplexNumber testZero;

    // Act
    testZero = complexZero / z;

    // Assert
    EXPECT_EQ(complexZero, testZero);
}

TEST(Okmyanskiy_Andrey_ComplexNumberTest, Multiply_Complex_And_One) {
    // Arrange
    double re = 15.0;
    double im = 2.0;
    ComplexNumber z(re, im);
    ComplexNumber complexOne(1.0, 0.0);
    ComplexNumber testOne;

    // Act
    testOne = complexOne * z;

    // Assert
    EXPECT_EQ(z, testOne);
}
