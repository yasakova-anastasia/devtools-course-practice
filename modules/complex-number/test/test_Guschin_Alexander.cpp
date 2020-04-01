// Copyright 2020 Guschin Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Guschin_Alexander_ComplexNumberTest, Can_Create) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Guschin_Alexander_ComplexNumberTest, Can_Plus) {
  double re_1 = 1.0;
  double im_1 = 2.0;
  double re_2 = 4.3;
  double im_2 = 1.2;

  ComplexNumber z(re_1, im_1);
  ComplexNumber x(re_2, im_2);
  ComplexNumber res(re_1 + re_2, im_1 + im_2);

  EXPECT_EQ(res, z + x);
}

TEST(Guschin_Alexander_ComplexNumberTest, Can_Compare_Two_Numbers) {
  double re_1 = 1.0;
  double im_1 = 2.0;
  double re_2 = re_1 + 1.0;
  double im_2 = im_1 + 1.0;

  ComplexNumber z(re_1, im_1);
  ComplexNumber x(re_2, im_2);

  EXPECT_EQ(z == x, false);
}
