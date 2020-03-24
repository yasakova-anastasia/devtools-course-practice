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
