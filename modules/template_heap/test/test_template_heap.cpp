// Copyright 2020 Pauzin_leonid

#include <gtest/gtest.h>
#include "include/template_heap.h"

TEST(THeap, Can_Create_int_heap) {
  ASSERT_NO_THROW(THeap<int>());
}

TEST(THeap, Can_Create_double_heap) {
  ASSERT_NO_THROW(THeap<double>());
}

TEST(THeap, Can_Create_char_heap) {
  ASSERT_NO_THROW(THeap<char>());
}

TEST(THeap, Can_insert_value) {
  THeap<int> a;
  ASSERT_NO_THROW(a.Push(3));
}