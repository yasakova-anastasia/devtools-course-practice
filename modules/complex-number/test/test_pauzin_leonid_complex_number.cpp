// Copyright 2020 Pauzin Leonid

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pauzin_Leonid_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Pauzin_Leonid_ComplexNumberTest, Can_Use_Default_Ctor) {
    // Arrange, Act, Assert
    EXPECT_NO_THROW(ComplexNumber());
}

TEST(Pauzin_Leonid_ComplexNumberTest, Can_Use_Copy_Ctor) {
    // Arrange
    double re = 1.0;
    double im = 3.1;	
	
	// Act
	ComplexNumber z1(re, im);
	ComplexNumber z2(z1);
	
	// Assert
    EXPECT_EQ(z1, z2);
}