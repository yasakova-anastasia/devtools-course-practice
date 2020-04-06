// Copyright 2020 Kuzhelev Anton

#include <gtest/gtest.h>
#include "include/TPrime_Nums.h"

TEST(TPrime_Nums, can_create_default_class) {
    ASSERT_NO_THROW(TPrime_Nums p());
}

TEST(TPrime_Nums, can_create_class_with_valid_parameters) {
    ASSERT_NO_THROW(TPrime_Nums p(3, 5));
}

TEST(TPrime_Nums, cannot_create_class_with_negative_piece) {
    ASSERT_ANY_THROW(TPrime_Nums p(-5, -3));
}

TEST(TPrime_Nums, can_create_class_with_negative_left_side) {
    ASSERT_NO_THROW(TPrime_Nums p(-3, 6));
}

TEST(TPrime_Nums, check_that_values_on_correct_position) {
    TPrime_Nums p(3, 5);
    std::pair<int, int> val = p.GetPiece();
    EXPECT_EQ(3, val.first);
    EXPECT_EQ(5, val.second);
}

TEST(TPrime_Nums, check_that_changes_left_side_if_right_is_correct) {
    TPrime_Nums p(-10, 20);
    std::pair<int, int> val = p.GetPiece();
    EXPECT_EQ(0, val.first);
}
