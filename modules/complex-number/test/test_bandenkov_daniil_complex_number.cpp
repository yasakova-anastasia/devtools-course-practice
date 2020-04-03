// Copyright 2020 Bandenkov Daniil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bandenkov_Daniil_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}
