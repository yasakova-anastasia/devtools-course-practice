// Copyright 2020 Kuzhelev Anton

#include <gtest/gtest.h>

#include <utility>
#include "include/TPrime_Nums.h"

bool compare_vec(std::vector<int> v1, std::vector<int> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for(int i = 0; i < v1.size(); ++i) {
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
}

TEST(TPrime_Nums, can_create_default_class) {
    ASSERT_NO_THROW(TPrime_Nums p());
}

TEST(TPrime_Nums, can_create_class_with_valid_parameters) {
    ASSERT_NO_THROW(TPrime_Nums p(3, 5));
}

TEST(TPrime_Nums, cannot_create_class_with_negative_piece) {
    ASSERT_ANY_THROW(TPrime_Nums p(-5, -3));
}

TEST(TPrime_Nums, cannot_create_class_with_negative_left_side) {
    ASSERT_ANY_THROW(TPrime_Nums p(-3, 6));
}

TEST(TPrime_Nums, cannot_create_class_if_left_is_bigger_than_right) {
    ASSERT_ANY_THROW(TPrime_Nums p(5, 2));
}

TEST(TPrime_Nums, check_that_values_on_correct_position) {
    TPrime_Nums p(3, 5);
    std::pair<int, int> val = p.GetPiece();

    EXPECT_EQ(3, val.first);
    EXPECT_EQ(5, val.second);
}

TEST(TPrime_Nums, check_that_no_primes_on_0_to_1) {
    TPrime_Nums p(0, 1);
    std::vector<int> primes = p.Get_Prime_Nums();

    EXPECT_EQ(0, primes.size());
}

TEST(TPrime_Nums, check_prime_nums_from_0_to_10) {
    TPrime_Nums p(0, 10);
    std::vector<int> res = p.Get_Prime_Nums();
    std::vector<int> tmp = {2, 3, 5, 7};

    EXPECT_TRUE(compare_vec(res, tmp));
}

TEST(TPrime_Nums, check_no_prime_nums_between_212_to_222) {
    TPrime_Nums p(212, 222);

    std::vector<int> res = p.Get_Prime_Nums();

    EXPECT_EQ(0, res.size());
}