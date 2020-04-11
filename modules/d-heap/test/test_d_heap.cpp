// Copyright 2020 Antipin Alexander

#include <gtest/gtest.h>
#include "include/d-heap.h"

TEST(Dheap, can_create_default_d_heap) {
    ASSERT_NO_THROW(d_heap());
}

TEST(Dheap, is_creating_default_d_heap_correct) {
    d_heap a;
    EXPECT_EQ(a.getD(), 2);
}

TEST(Dheap, can_create_d_heap_with_two_parameters) {
    ASSERT_NO_THROW(d_heap(2, 10));
}

TEST(Dheap, is_creating_d_heap_with_two_parameters_correct) {
    d_heap a(3, 10);
    EXPECT_EQ(a.getD(), 3);
}

TEST(Dheap, can_create_d_heap_from_copy) {
    d_heap copy(2, 10);
    ASSERT_NO_THROW(d_heap(copy));
}

TEST(Dheap, can_create_d_heap_from_move_constructor) {
    ASSERT_NO_THROW(d_heap(d_heap(2, 10)));
}