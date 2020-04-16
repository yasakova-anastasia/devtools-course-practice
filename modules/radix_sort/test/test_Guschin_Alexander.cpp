// Copyright 2020 Guschin Alexander

#include <gtest/gtest.h>

#include "include/radix_sort.h"

TEST(RadixSortTest, Can_Fill_Vector) { 
  std::vector<std::int32_t> vec(3, 0);
  std::vector<std::int32_t> old_vec(3, 0);

  Fill_Random(&vec);

  EXPECT_EQ(vec != old_vec, true);
}
