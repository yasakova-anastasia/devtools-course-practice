// Copyright 2020 Guschin Alexander

#include <gtest/gtest.h>

#include <vector>
#include "include/radix_sort.h"

TEST(RadixSortTest, Can_Fill_Array) {
  std::vector<std::int32_t> vec(3, 0);
  std::vector<std::int32_t> old_vec(3, 0);

  FillRandom(&vec);

  EXPECT_EQ(true, vec != old_vec);
}

TEST(RadixSortTest, Can_Find_Unsorted_Array) {
  std::vector<std::int32_t> vec = {1, 4, 2};

  bool result = IsSorted(vec);

  EXPECT_EQ(false, result);
}

TEST(RadixSortTest, Can_Find_Sorted_Array) {
  std::vector<std::int32_t> vec = {1, 2, 4};

  bool result = IsSorted(vec);

  EXPECT_EQ(true, result);
}

TEST(RadixSortTest, Can_Sort_Sorted_Array) {
  std::vector<std::int32_t> vec = {1, 2, 4};
  std::vector<std::int32_t> res_exp = {1, 2, 4};
  std::vector<std::int32_t> tmp_vec;

  tmp_vec = RadixSort(vec);

  EXPECT_EQ(res_exp, tmp_vec);
}

