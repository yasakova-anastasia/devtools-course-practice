// Copyright 2020 Pauzin Leonid

#include <gtest/gtest.h>
#include "include/template_heap.h"


TEST(THeap, Can_create_int_heap) {
  ASSERT_NO_THROW(THeap<int>());
}

TEST(THeap, Can_create_double_heap) {
  ASSERT_NO_THROW(THeap<double>());
}

TEST(THeap, Can_create_char_heap) {
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
  int k;
  a.Push(5);
  k = a.Remove();

  ASSERT_EQ(k, 5);
}

TEST(THeap, Remove_from_empty_heap) {
  THeap<int> a;

  a.Push(5);
  int k = a.Remove();

  ASSERT_ANY_THROW(a.Remove());
}

TEST(THeap, Can_print_heap) {
  THeap<int> a;

  a.Push(5);
  a.Push(8);
  a.Push(10);

  ASSERT_NO_THROW(a.PrintHeap());
}

TEST(THeap, Can_get_size) {
  THeap<int> a;

  a.Push(5);
  a.Push(8);
  a.Push(10);

  ASSERT_EQ(3, a.GetSize());
}

TEST(THeap, Can_use_copy_ctor) {
  THeap<int> a;

  a.Push(5);
  a.Push(8);

  THeap<int> b(a);

  for (size_t i = 0; i < a.GetSize(); i++) {
    ASSERT_EQ(a.Remove(), b.Remove());
  }
}

TEST(THeap, Can_use_assignment_operator) {
  THeap<int> a;
  THeap<int> b;

  a.Push(5);
  a.Push(8);
  b = a;

  for (size_t i = 0; i < a.GetSize(); i++) {
    ASSERT_EQ(a.Remove(), b.Remove());
  }
}

TEST(Theap, Test_for_cov1) {
  THeap<int> a;
  a.Push(5);
  a.Push(28);
  a.Push(17);
  a.Push(8);
  
  a.Remove();
  a.Remove();
  a.Remove();
  a.Remove();

  ASSERT_ANY_THROW(a.Remove());
}
