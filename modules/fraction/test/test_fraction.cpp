// Copyright 2020 Baldin Alexey

#include <gtest/gtest.h>

#include "include/fraction.h"

class FractionTest : public ::testing::Test {
};

TEST_F(FractionTest, Can_Create_Fraction) {
    // Arrange
    // Act
    Fraction f(1.0, 1.0);

    // Assert
    EXPECT_EQ(1.0, f.getNominator());
    EXPECT_EQ(1.0, f.getDenominator());
}

TEST_F(FractionTest, Denominator_Cant_Be_Zero) {
    // Arrange
    Fraction f1(1.0, 1.0);

    // Act
    // Assert
    EXPECT_ANY_THROW(f1.setDenominator(0.0));
    EXPECT_ANY_THROW(Fraction f2(1.0, 0.0));
}

TEST_F(FractionTest, Can_Create_Fraction_With_Copy_Constructor) {
    // Arrange
    Fraction f1(1.0, 1.0);

    // Act
    Fraction f2(f1);

    // Assert
    EXPECT_EQ(f1, f2);
}

TEST_F(FractionTest, Equals_Fractions_Is_Equals) {
    // Arrange
    Fraction f1(1.0, 1.0);
    Fraction f2(1.0, 1.0);

    // Act
    // Assert
    EXPECT_EQ(f1, f2);
}

TEST_F(FractionTest, Different_Fractions_Is_Different) {
    // Arrange
    Fraction f1(1.0, 1.0);
    Fraction f2(2.0, 2.0);

    // Act
    // Assert
    EXPECT_NE(f1, f2);
}

TEST_F(FractionTest, NOD_Test) {
    // Arrange
    int a = 30;
    int b = 45;
    int c = 0;

    // Act
    c = nod(b, a);

    // Assert
    EXPECT_EQ(c, 15);
}
