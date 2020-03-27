// Copyright 2020 Maximova Irina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Maximova_Irina_ComplexNumberTest, Can_Create_Default_Without_Throw) {
  // Arrange Act Assert
  ASSERT_NO_THROW(ComplexNumber());
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Create_Default_Zero) {
  // Arrange
  double def = 0.0;

  // Act
  ComplexNumber z;

  // Assert
  EXPECT_EQ(def, z.getRe());
  EXPECT_EQ(def, z.getIm());
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Create_With_Real_And_Imaginary) {
  // Arrange
  double re = -3.0;
  double im = 5.6;

  // Act
  ComplexNumber z(re, im);

  // Assert
  ASSERT_EQ(re, z.getRe());
  ASSERT_EQ(im, z.getIm());
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Equate) {
  // Arrange
  ComplexNumber a;
  ComplexNumber b(1.5, 3.0);

  // Act
  a = b;

  // Assert
  ASSERT_EQ(a, b);
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Create_Copy) {
  // Arrange
  ComplexNumber z(1.1, 0.6);

  // Act
  ComplexNumber expected_z(z);

  // Assert
  EXPECT_EQ(expected_z, z);
}






