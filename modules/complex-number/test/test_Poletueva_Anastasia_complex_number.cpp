// Copyright 2020 Poletueva Anastasia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Poletueva_Anastasia_ComplexNumberTest, Can_Create_With_Negative_Re_And_Im) {
    // Arrange
    double re = -1.2;
    double im = -5.3;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}



