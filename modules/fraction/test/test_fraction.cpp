// Copyright 2020 Baldin Alexey

#include <gtest/gtest.h>

#include "include/fraction.h"

class FractionTest : public ::testing::Test {
};

TEST_F(FractionTest, Can_Create_Fraction) {
    // Arrange
    // Act
    Fraction f(1, 1);

    // Assert
    EXPECT_EQ(1, f.getNominator());
    EXPECT_EQ(1, f.getDenominator());
}

TEST_F(FractionTest, Denominator_Cant_Be_Zero) {
    // Arrange
    Fraction f1(1, 1);

    // Act
    // Assert
    EXPECT_ANY_THROW(f1.setDenominator(0));
    EXPECT_ANY_THROW(Fraction f2(1, 0));
}

TEST_F(FractionTest, Can_Create_Fraction_With_Copy_Constructor) {
    // Arrange
    Fraction f1(1, 1);

    // Act
    Fraction f2(f1);

    // Assert
    EXPECT_EQ(f1, f2);
}

TEST_F(FractionTest, Equals_Fractions_Is_Equals) {
    // Arrange
    Fraction f1(1, 2);
    Fraction f2(2, 4);

    // Act
    // Assert
    EXPECT_EQ(f1, f2);
}

TEST_F(FractionTest, Different_Fractions_Is_Different) {
    // Arrange
    Fraction f1(1, 1);
    Fraction f2(2, 1);

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

TEST_F(FractionTest, Denominator_Cant_Be_Negative) {
    // Arrange
    Fraction f(1, -1);

    // Act
    // Assert
    EXPECT_GT(f.getDenominator(), 0);
}

TEST_F(FractionTest, Correct_Fraction_Reduction) {
    // Arrange
    Fraction f(5, 10);

    // Act
    f.fractionReduction();

    // Assert
    EXPECT_EQ(f.getNominator(), 1);
    EXPECT_EQ(f.getDenominator(), 2);
}

TEST_F(FractionTest, Addition_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    Fraction f3 = f1 + f2;

    // Assert
    EXPECT_EQ(f3.getNominator(), 2);
    EXPECT_EQ(f3.getDenominator(), 3);
}

TEST_F(FractionTest, Subtraction_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    Fraction f3 = f1 - f2;

    // Assert
    EXPECT_EQ(f3.getNominator(), -8);
    EXPECT_EQ(f3.getDenominator(), 15);
}

TEST_F(FractionTest, Multiplication_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    Fraction f3 = f1 * f2;

    // Assert
    EXPECT_EQ(f3.getNominator(), 1);
    EXPECT_EQ(f3.getDenominator(), 25);
}

TEST_F(FractionTest, Division_Fractions_Test) {
    // Arrange
    Fraction f1(1, 15);
    Fraction f2(3, 5);

    // Act
    Fraction f3 = f1 / f2;

    // Assert
    EXPECT_EQ(f3.getNominator(), 1);
    EXPECT_EQ(f3.getDenominator(), 9);
}

TEST_F(FractionTest, Assignment_Test) {
    // Arrange
    Fraction f1(1, 1);

    // Act
    Fraction f2 = f1;

    // Assert
    EXPECT_EQ(f1, f2);
}
