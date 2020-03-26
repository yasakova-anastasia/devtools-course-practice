// Copyright 2020 Isaev Ilya

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"

TEST(Ilya_Isaev_Complex_Number_Test, Create_Instance_With_Params) {
    auto a = ComplexNumber(1.05, 2.15);

    EXPECT_EQ(1.05, a.getRe());
    EXPECT_EQ(2.15, a.getIm());
}
