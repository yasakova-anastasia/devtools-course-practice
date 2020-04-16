// Copyright 2020 Guschin Alexander

#include <gtest/gtest.h>

#include <vector>
#include "include/radix_sort.h"

TEST(RadixSortTest, Can_Fill_Array) {
  std::vector<std::int32_t> vec(3, 0);
  std::vector<std::int32_t> old_vec(3, 0);

  FillRandom(&vec);

  EXPECT_EQ(vec != old_vec, true);
}

TEST(RadixSortTest, Can_Find_Unsorted_Array) {
  std::vector<std::int32_t> vec = {1, 4, 2};

  bool result = IsSorted(vec);

  EXPECT_EQ(result, false);
}

TEST(RadixSortTest, Can_Find_Sorted_Array) {
  std::vector<std::int32_t> vec = {1, 2, 4};

  bool result = IsSorted(vec);

  EXPECT_EQ(result, true);
}


