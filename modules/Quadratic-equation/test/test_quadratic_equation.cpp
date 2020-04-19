// Copyright 2020 Arisova Anastasiia

#include <gtest/gtest.h>
#include <vector>

#include "include/Quadratic-equation.h"

TEST(QuadraticEquationTest, Can_Create_Quadratic_Equation) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(QuadraticEquation equat(2, 4, 1));
}

TEST(QuadraticEquationTest, Can_Create_Quadratic_Equation_First_Coeff_Equal_Zero) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(QuadraticEquation equat(0, 4, 1));
}

TEST(QuadraticEquationTest, Can_Get_First_Root) {
    // Arrange
    QuadraticEquation equat(1, -2, 1);
    double root = 1.0;

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(root, equat.GetRoot1());
}

TEST(QuadraticEquationTest, Can_Get_Second_Root) {
    // Arrange
    QuadraticEquation equat(1, -2, 1);
    double root = 1.0;

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(root, equat.GetRoot2());
}

TEST(QuadraticEquationTest, Can_Find_Root) {
    // Arrange
    QuadraticEquation equat(1, -2, 1);

    // Assert
    EXPECT_NO_THROW(equat.SolveQuadraticEquation(););
}
