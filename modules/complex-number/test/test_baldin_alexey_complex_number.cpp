// Copyright 2020 Baldin Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Baldin_Alexey_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Baldin_Alexey_ComplexNumberTest, Multiple_By_Zero) {
	// Arrange
	double re = 123.0;
	double im = 456.0;

	// Act
	ComplexNumber z(re, im);
	ComplexNumber zero(0.0, 0.0);
	z = z * zero;

	// Assert
	EXPECT_EQ(z.getRe(), 0.0);
	EXPECT_EQ(z.getIm(), 0.0);
}
