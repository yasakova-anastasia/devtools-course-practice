// Copyright 2020 Golubeva Anna

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Golubeva_Anna_ComplexNumberTest, Copy_Constructor) {
  // Arrange
  ComplexNumber num1(3.3, 2.2);

  // Act
  ComplexNumber num2(num1);

  // Assert
  EXPECT_EQ(num1, num2);
}