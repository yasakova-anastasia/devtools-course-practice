// Copyright 2020 Pauzin_leonid

#include <gtest/gtest.h>
#include "include/template_heap.h"

TEST(Theap, Can_Create_int_heap) {
  ASSERT_NO_THROW(THeap<int>());
}

TEST(Theap, Can_Create_double_heap) {
  ASSERT_NO_THROW(THeap<double>());
}

TEST(Theap, Can_Create_char_heap) {
  ASSERT_NO_THROW(THeap<char>());
}
