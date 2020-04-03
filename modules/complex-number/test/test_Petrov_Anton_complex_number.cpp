// Copyright 2020 Petrov Anton

#include <gtest/gtest.h>

#include "include/complex_number.h"



TEST(Petrov_Anton_ComplexNumberTest, Can_Be_Float ) {
	// Arrange
	float re = 1.11;
	float im = 1.11;

	// Act
	ComplexNumber z(re, im);
	// Assert
	ASSERT_FLOAT_EQ(re, z.getRe());
	ASSERT_FLOAT_EQ(im, z.getIm());
}

