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

TEST(THeap, Cam_remove_value) {
  THeap<int> a;
  a.Push(5);
  ASSERT_NO_THROW(a.Remove());
}

TEST(THeap, Cam_insert_and_remove_value) {
  THeap<int> a;
  a.Push(5);
  int k = a.Remove();
  ASSERT_EQ(k, 5);
}
