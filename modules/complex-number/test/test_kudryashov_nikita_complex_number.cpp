// Copyright 2020 Kudryashov Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kudryashov_Nikita_ComplexNumberTest, Adding_Zero_Change_Nothing) {
    // Arrange
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber temp(128.25, 0.25);
    double re = 128.25;
    double im = 0.25;

    // Act
    temp = temp + zero;

    // Assert
    EXPECT_EQ(re, temp.getRe());
    EXPECT_EQ(im, temp.getIm());
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Subtracting_Zero_Change_Nothing)) {
    // Arrange
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber temp(11.0, 732.0);
    double re = 11.0;
    double im = 732.0;

    // Act
    temp = temp - zero;

    // Assert
    EXPECT_EQ(re, temp.getRe());
    EXPECT_EQ(im, temp.getIm());
}



