// Copyright 2020 Myshkin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Myshkin_Andrey_ComplexNumberTest, Can_Create_Number) {
    const double real = 12.0;
    const double imag = 45.4;

    ComplexNumber num(real, imag);

    EXPECT_EQ(real, num.getRe());
    EXPECT_EQ(imag, num.getIm());
}


TEST(Myshkin_Andrey_ComplexNumberTest, Work_With_Constructor) {
    const double real = 1.1;
    const double imag = 20.0;

    ComplexNumber num1(real, imag);
    ComplexNumber num2;

    num2 = num1;

    ASSERT_EQ(num1, num2);
}
