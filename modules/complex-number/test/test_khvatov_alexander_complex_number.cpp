// Copyright 2020 Khvatov Alexander

#include <limits>

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Khvatov_Alexander_ComplexNumberTest, can_create_complex_number) {
    // Arrange, Act, Assert
    EXPECT_NO_THROW(ComplexNumber());
}

TEST(Khvatov_Alexander_ComplexNumberTest, can_create_complex_number_with_inf) {
    // Arrange
    double re = std::numeric_limits<double>::infinity();
    double im = std::numeric_limits<double>::infinity();

    // Act, Assert
    EXPECT_NO_THROW(ComplexNumber z(re, im));
}

TEST(Khvatov_Alexander_ComplexNumberTest, DISABLED_cant_create_complex_number_with_NaN) {
    // Arrange
    double re = std::numeric_limits<double>::quiet_NaN();
    double im = std::numeric_limits<double>::quiet_NaN();

    // Act, Assert
    EXPECT_ANY_THROW(ComplexNumber z(re, im));
}

TEST(Khvatov_Alexander_ComplexNumberTest, complex_number_with_inf_not_equal_complex_number) {
    // Arrange
    double re = std::numeric_limits<double>::infinity();
    double im = std::numeric_limits<double>::infinity();

    // Act
    ComplexNumber z1(re, im), z2;

    // Assert
    EXPECT_NE(z1, z2);
}
