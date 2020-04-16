// Copyright 2020 Guschin Alexander

#include <gtest/gtest.h>

#include <vector>
#include "include/radix_sort.h"

TEST(RadixSortTest, Can_Fill_Array) {
  std::vector<std::int32_t> vec(3, 0);
  std::vector<std::int32_t> old_vec(3, 0);

  FillRandom(&vec);

  EXPECT_TRUE(vec != old_vec);
}

TEST(RadixSortTest, Can_Find_Unsorted_Array) {
  std::vector<std::int32_t> vec = {1, 4, 2};

  bool result = IsSorted(vec);

  EXPECT_FALSE(result);
}

TEST(RadixSortTest, Can_Find_Sorted_Array) {
  std::vector<std::int32_t> vec = {1, 2, 4};

  bool result = IsSorted(vec);

  EXPECT_TRUE(result);
}

TEST(RadixSortTest, Can_Sort_Sorted_Array) {
  std::vector<std::int32_t> vec = {1, 2, 4};
  std::vector<std::int32_t> expected_vec = {1, 2, 4};
  std::vector<std::int32_t> tmp_vec;

  tmp_vec = RadixSort(vec);

  EXPECT_EQ(expected_vec, tmp_vec);
}

TEST(RadixSortTest, Can_Sort_Unsorted_Array) {
  std::vector<std::int32_t> vec = {1, 2, 4};
  std::vector<std::int32_t> expected_vec = {1, 2, 4};
  std::vector<std::int32_t> tmp_vec;

  tmp_vec = RadixSort(vec);

  EXPECT_EQ(expected_vec, tmp_vec);
}

TEST(RadixSortTest, Can_Sort_Unsorted_Array_With_Negative_Numbers) {
  std::vector<std::int32_t> vec = {
      -32, 332, 1 << 28, -8, 1 << 26, -(1 << 26), -24, -(1 << 27), 1111};
  std::vector<std::int32_t> expected_vec = {
      -(1 << 27), -(1 << 26), -32, -24, -8, 332, 1111, 1 << 26, 1 << 28};

  std::vector<std::int32_t> res(RadixSort(vec));

  EXPECT_EQ(expected_vec, res);
}
