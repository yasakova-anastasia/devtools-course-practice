// Copyright 2020 Arisova Anastasiia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Arisova_Anastasiia_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Arisova_Anastasiia_ComplexNumberTest, Can_Multiplication_Zero) {
    // Arrange
    ComplexNumber z1(2.0, 5.4);
    ComplexNumber z2(0.0, 0.0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    ComplexNumber answer(0.0, 0.0);
    EXPECT_EQ(answer, z);
}

TEST(Arisova_Anastasiia_ComplexNumberTest, Can_Multiplication_By_Itself) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);

    // Act
    ComplexNumber z = z1 * z1;

    // Assert
    ComplexNumber answer(-3.0, 4.0);
    EXPECT_EQ(answer, z);
}

TEST(Arisova_Anastasiia_ComplexNumberTest, Can_Swap_Summand) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(0.4, 3.0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    ComplexNumber answer = z2 + z1;
    EXPECT_EQ(answer, z);
}
