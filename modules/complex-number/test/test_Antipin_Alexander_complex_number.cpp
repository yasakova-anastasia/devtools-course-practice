// Copyright 2020 Antipin Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Antipin_Alexander_ComplexNumberTest,
    can_create_complex_number_without_throws) {
    ASSERT_NO_THROW(ComplexNumber(1.0, 2.0));
}

TEST(Antipin_Alexander_ComplexNumberTest,
    can_create_complex_number_correct_1) {
    double re{};
    double im{ 1.0 };

    ComplexNumber nomber(re, im);

    EXPECT_EQ(0.0, nomber.getRe());
}

TEST(Antipin_Alexander_ComplexNumberTest,
    can_create_complex_number_correct_2) {
    double re{};
    double im{ 1.0 };

    ComplexNumber nomber(re, im);

    EXPECT_EQ(1.0, nomber.getIm());
}

TEST(Antipin_Alexander_ComplexNumberTest, can_compare_correct_1) {
    double re{};
    double im{ 1.0 };

    ComplexNumber nomber1(re, im);
    ComplexNumber nomber2(0.0, 1.0);

    EXPECT_EQ(nomber1, nomber2);
}

TEST(Antipin_Alexander_ComplexNumberTest, can_compare_correct_2) {
    double re{};
    double im{ 1.0 };

    ComplexNumber nomber1(re, im);
    ComplexNumber nomber2(1.0, 1.0);

    EXPECT_NE(nomber1, nomber2);
}