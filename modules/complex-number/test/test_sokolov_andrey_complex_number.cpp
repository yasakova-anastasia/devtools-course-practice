// Copyright 2020 Sokolov Andrey

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Sokolov_Andrey_ComplexNumberTest, default_constructor) {
  // Arrange
  ComplexNumber z{};

  // Assert
  EXPECT_EQ(z.getRe(), 0);
  EXPECT_EQ(z.getIm(), 0);
}

TEST(Sokolov_Andrey_ComplexNumberTest, initialization_constructor) {
  // Arrange
  ComplexNumber z{1, -1};

  // Assert
  EXPECT_EQ(z.getRe(), 1);
  EXPECT_EQ(z.getIm(), -1);
}

TEST(Sokolov_Andrey_ComplexNumberTest, copy_constructor) {
  // Arrange
  ComplexNumber z1{1, -1};
  ComplexNumber z{z1};

  // Assert
  EXPECT_EQ(z2.getRe(), z1.getRe());
  EXPECT_EQ(z2.getIm(), z1.getIm());
}

TEST(Sokolov_Andrey_ComplexNumberTest, get_real_part) {
  // Arrange
  ComplexNumber z{1, -1};

  // Act
  int a = z.getRe();

  // Assert
  EXPECT_EQ(a, 1);
}

TEST(Sokolov_Andrey_ComplexNumberTest, get_imaginary_part) {
  // Arrange
  ComplexNumber z{1, -1};

  // Act
  int a = z.getIm();

  // Assert
  EXPECT_EQ(a, -1);
}

TEST(Sokolov_Andrey_ComplexNumberTest, set_real_part) {
  // Arrange
  ComplexNumber z{};

  // Act
  z.setRe(1);

  // Assert
  EXPECT_EQ(z.getRe(), 1);
}

TEST(Sokolov_Andrey_ComplexNumberTest, set_imaginary_part) {
  // Arrange
  ComplexNumber z{};

  // Act
  z.setIm(1);

  // Assert
  EXPECT_EQ(z.getIm(), 1);
}

TEST(Sokolov_Andrey_ComplexNumberTest, addition_operator) {
  // Arrange
  ComplexNumber z1{1, 0};
  ComplexNumber z2{0, 1};
  ComplexNumber z3{};

  // Act
  z3 = z1 + z2;

  // Assert
  EXPECT_EQ(z3.getRe(), 1);
  EXPECT_EQ(z3.getIm(), 1);
}

TEST(Sokolov_Andrey_ComplexNumberTest, subtraction_operator) {
  // Arrange
  ComplexNumber z1{2, 2};
  ComplexNumber z2{1, 1};
  ComplexNumber z3{};

  // Act
  z3 = z1 - z2;

  // Assert
  EXPECT_EQ(z3.getRe(), 1);
  EXPECT_EQ(z3.getIm(), 1);
}

TEST(Sokolov_Andrey_ComplexNumberTest, multiplication_operator) {
  // Arrange
  ComplexNumber z1{2, 3};
  ComplexNumber z2{-1, 1};
  ComplexNumber z3{};

  // Act
  z3 = z1 * z2;

  // Assert
  EXPECT_EQ(z3.getRe(), -5);
  EXPECT_EQ(z3.getIm(), -1);
}

TEST(Sokolov_Andrey_ComplexNumberTest, division_operator) {
  // Arrange
  ComplexNumber z1{-2, 1};
  ComplexNumber z2{1, -1};
  ComplexNumber z3{};

  // Act
  z3 = z1 / z2;

  // Assert
  EXPECT_EQ(z3.getRe(), -1.5);
  EXPECT_EQ(z3.getIm(), -0.5);
}

TEST(Sokolov_Andrey_ComplexNumberTest, equal_operator_false) {
  // Arrange
  ComplexNumber z1{2, 3};
  ComplexNumber z2{-1, 1};
  bool result;

  // Act
  result = z1 == z2;

  // Assert
  EXPECT_EQ(result, false);
}

TEST(Sokolov_Andrey_ComplexNumberTest, equal_operator_true) {
  // Arrange
  ComplexNumber z1{2, 2};
  ComplexNumber z2{2, 2};
  bool result;

  // Act
  result = z1 == z2;

  // Assert
  EXPECT_EQ(result, true);
}

TEST(Sokolov_Andrey_ComplexNumberTest, not_equal_operator_true) {
  // Arrange
  ComplexNumber z1{2, 2};
  ComplexNumber z2{2, 1};
  bool result;

  // Act
  result = z1 != z2;

  // Assert
  EXPECT_EQ(result, true);
}

TEST(Sokolov_Andrey_ComplexNumberTest, not_equal_operator_false) {
  // Arrange
  ComplexNumber z1{2, 2};
  ComplexNumber z2{2, 2};
  bool result;

  // Act
  result = z1 != z2;

  // Assert
  EXPECT_EQ(result, false);
}