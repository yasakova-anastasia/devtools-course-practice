// Copyright 2020 Mazur Daniil

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Mazur_Daniil_ComplexNumberTest, Can_Default_Constructor) {
  // Arrange
  ComplexNumber z{};

  // Assert
  EXPECT_EQ(z.getRe(), 0);
  EXPECT_EQ(z.getIm(), 0);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Initialization_Constructor) {
  // Arrange
  ComplexNumber z{3, 4};

  // Assert
  EXPECT_EQ(z.getRe(), 3);
  EXPECT_EQ(z.getIm(), 4);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Copy_Constructor) {
  // Arrange
  ComplexNumber z1{2, -6.3};
  ComplexNumber z2{z1};

  // Assert
  EXPECT_EQ(z2.getRe(), z1.getRe());
  EXPECT_EQ(z2.getIm(), z1.getIm());
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Get_Real_Part) {
  // Arrange
  ComplexNumber z{3, 2};

  // Act
  double a = z.getRe();

  // Assert
  EXPECT_EQ(a, 3);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Get_Imaginary_Part) {
  // Arrange
  ComplexNumber z{3, 2};

  // Act
  double a = z.getIm();

  // Assert
  EXPECT_EQ(a, 2);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Set_Real_Part) {
  // Arrange
  ComplexNumber z{};

  // Act
  z.setRe(5);

  // Assert
  EXPECT_EQ(z.getRe(), 5);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Set_Imaginary_Part) {
  // Arrange
  ComplexNumber z{};

  // Act
  z.setIm(3.2);

  // Assert
  EXPECT_EQ(z.getIm(), 3.2);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Addition_Operator) {
  // Arrange
  ComplexNumber z1{1, 1};
  ComplexNumber z2{3, 4};
  ComplexNumber z3{};

  // Act
  z3 = z1 + z2;

  // Assert
  EXPECT_EQ(z3.getRe(), 4);
  EXPECT_EQ(z3.getIm(), 5);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Subtraction_Operator) {
  // Arrange
  ComplexNumber z1{4, 5};
  ComplexNumber z2{2, 2};
  ComplexNumber z3{};

  // Act
  z3 = z1 - z2;

  // Assert
  EXPECT_EQ(z3.getRe(), 2);
  EXPECT_EQ(z3.getIm(), 3);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Compare_Equal) {
  // Arrange
  double re = 2.3;
  double im = 4.5;

  // Act
  ComplexNumber z1(re, im);
  ComplexNumber z2(re, im);

  // Assert
  EXPECT_EQ(z1, z2);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Compare_Not_Equal) {
    // Arrange
  double re1 = 3.4;
  double im1 = 2.6;
  double re2 = 2.4;
  double im2 = 2.6;

  // Act
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);

  // Assert
  EXPECT_NE(z1, z2);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Multiplication) {
  // Arrange
  double re1 = 1.6;
  double im1 = 1.2;
  double re2 = 1.1;
  double im2 = 4.6;
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);

  // Act
  ComplexNumber z3(re1 * re2 - im1 * im2, re1 * im2 + re2 * im1);
  // Assert
  EXPECT_EQ(z3, z1 * z2);
}

TEST(Mazur_Daniil_ComplexNumberTest, Can_Division) {
  // Arrange
  double re1 = 1;
  double im1 = 1;
  double re2 = 1;
  double im2 = 1;
  ComplexNumber z1(re1, im1);
  ComplexNumber z2(re2, im2);

  // Act
  ComplexNumber z3((re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2),
    (im1 * re2 - re1 * im2) / (re2 * re2 + im2 * im2));

  // Assert
  EXPECT_EQ(z3, z1 / z2);
}
