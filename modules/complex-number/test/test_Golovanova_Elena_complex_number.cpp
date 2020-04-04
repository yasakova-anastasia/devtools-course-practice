// Copyright 2020 Golovanova Elena

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Complex) {
  // Arrange
  double re = 3.4;
  double im = 9.0;

  // Act
  ComplexNumber z(re, im);

  // Assert
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

//TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Zero) {
//  // Arrange
//  double re = 3.4;
//  double im = 9.0;
//
//  // Act
//  ComplexNumber z(re, im);
//
//  // Assert
//  EXPECT_EQ(re, z.getRe());
//  EXPECT_EQ(im, z.getIm());
//}