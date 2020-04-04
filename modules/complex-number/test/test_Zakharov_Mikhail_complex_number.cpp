// Copyright 2020 Zakharov Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zakharov_Mikhail_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 13.37;
    double im = 22.88;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
