// Copyright 2020 Golubeva Anna

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Golubeva_Anna_ComplexNumberTest, Can_Set_Real_And_Imaginary) {
// Arrange
  ComplexNumber num;
  double real = 2.2;
  double imaginary = 1.1;

  // Act
  num.setRe(real);
  num.setIm(imaginary);

  // Assert
  ASSERT_EQ(real, num.getRe());
  ASSERT_EQ(imaginary, num.getIm());
}

TEST(Golubeva_Anna_ComplexNumberTest, Copy_Constructor) {
  // Arrange
  ComplexNumber num1(3.3, 2.2);

  // Act
  ComplexNumber num2(num1);

  // Assert
  EXPECT_EQ(num1, num2);
}




