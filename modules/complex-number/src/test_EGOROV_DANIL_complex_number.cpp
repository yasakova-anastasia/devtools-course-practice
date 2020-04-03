// Copyright 2020 Egorov Danil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Egorov_Danil_ComplexNumberTest, Can_Compare_Equal) {
    // Arrange
    double re = 1.5;
    double im = 1.5;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);

    // Assert
    EXPECT_EQ(z1, z2);
}
