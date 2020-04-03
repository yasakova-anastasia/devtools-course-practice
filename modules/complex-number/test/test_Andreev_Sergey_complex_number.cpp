// Copyright 2020 Andreev Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Andreev_Sergey_ComplexNumberTest, Comprasion_Equals_Sum) {
	// Arrange
	double re = 10;
	double im = 10;
	double re2 = 10;
	double im2 = 10;

	// Act
	ComplexNumber z1(re, im);
	ComplexNumber z2(re2, im2);
	ComplexNumber z3(re + re2, im + im2);

	z2 = z2 + z1;

	// Assert
	EXPECT_EQ(z2, z3);
}



