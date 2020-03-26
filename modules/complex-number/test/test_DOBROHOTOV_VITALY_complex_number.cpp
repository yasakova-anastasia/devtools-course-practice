// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Check_Default_Constructor) {
    // Act
    ComplexNumber z;

    // Assert
    EXPECT_EQ(0, z.getRe());
    EXPECT_EQ(0, z.getIm());
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Check_Parameterized_Constructor) {
    // Arrange
    double re = 20.0;
    double im = 5.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Check_Copy_Constructor) {
    // Arrange
    ComplexNumber z1(2.0, 4.0);

    // Act
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Two_Complex_Numbers_Are_Equal_Return_True) {
    // Arrange
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(z1);

    // Assert
    EXPECT_TRUE(z1==z2);
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Two_Complex_Numbers_Are_Equal_Return_False) {
    // Arrange
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(2.1, 4.0);

    // Assert
    EXPECT_FALSE(z1 == z2);
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Two_Complex_Numbers_Are_Not_Equal_Return_True) {
    // Arrange
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(2.1, 4.0);

    // Assert
    EXPECT_TRUE( z1 != z2);
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Two_Complex_Numbers_Are_Not_Equal_Return_False) {
    // Arrange
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(2.0, 4.0);

    // Assert
    EXPECT_FALSE( z1 != z2);
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Can_Assign_Complex_Number) {
    // Arrange
    ComplexNumber z1(2.0, 5.0);
    ComplexNumber z2;

    // Act
    z2 = z1;

    // Assert
    EXPECT_TRUE(z1==z2);
}
