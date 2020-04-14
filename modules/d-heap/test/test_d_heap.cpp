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

TEST(Dheap, is_creating_default_d_heap_return_correct_values) {
    d_heap a;
    size_t i = -1;
    EXPECT_EQ(a[0], i);
}

TEST(Dheap, can_create_d_heap_with_two_parameters) {
    ASSERT_NO_THROW(d_heap(2, 10));
}

TEST(Dheap, is_creating_d_heap_with_two_parameters_correct) {
    d_heap a(3, 10);
    EXPECT_EQ(a.getD(), 3);
}

TEST(Dheap, is_creating_d_heap_with_two_parameters_return_correct_values) {
    d_heap a(3, 10);
    size_t i = -1;
    EXPECT_EQ(a[0], i);
}


TEST(Dheap, can_create_d_heap_from_copy) {
    d_heap copy(2, 10);
    ASSERT_NO_THROW(d_heap a(copy));
}

TEST(Dheap, is_creating_d_heap_from_copy_correct) {
    d_heap copy(3, 10);
    d_heap a(copy);
    EXPECT_EQ(a.getD(), 3);
}

TEST(Dheap, is_creating_d_heap_from_copy_return_correct_values) {
    d_heap copy(3, 10);
    d_heap a(copy);
    size_t i = -1;
    EXPECT_EQ(a[0], i);
}

TEST(Dheap, can_create_d_heap_from_move_constructor) {
    d_heap copy(2, 10);
    ASSERT_NO_THROW(d_heap a(std::move(copy)));
}

TEST(Dheap, is_creating_d_heap_from_move_correct) {
    d_heap copy(3, 10);
    d_heap a(std::move(copy));
    EXPECT_EQ(a.getD(), 3);
}

TEST(Dheap, is_creating_d_heap_from_move_return_correct_values) {
    d_heap copy(3, 10);
    d_heap a(std::move(copy));
    size_t i = -1;
    EXPECT_EQ(a[0], i);
}

TEST(Dheap, can_return_first_child) {
    d_heap a(3, 10);
    a[0] = 2;
    a[1] = 4;
    a[2] = 3;
    EXPECT_EQ(a.firstChild(0), 1);
}

TEST(Dheap, can_return_last_child) {
    d_heap a(3, 10);
    a[0] = 2;
    a[1] = 4;
    a[2] = 3;
    EXPECT_EQ(a.lastChild(0), 3);
}

TEST(Dheap, can_return_min_child) {
    d_heap a(3, 10);
    a[0] = 2;
    a[1] = 4;
    a[2] = 3;
    EXPECT_EQ(a.minChild(0), 2);
}

TEST(Dheap, can_return_father) {
    d_heap a(3, 10);
    a[0] = 2;
    a[1] = 4;
    a[2] = 3;
    EXPECT_EQ(a.father(2), 0);
}

TEST(Dheap, can_ascent_element) {
    d_heap a(3, 10);
    a[0] = 2; a[1] = 4;
    a[2] = 3; a[3] = 5;
    a[4] = 1;
    a.ascent(4);
    EXPECT_EQ(a[0], 1);
}

TEST(Dheap, can_immersion_element) {
    d_heap a(3, 10);
    a[0] = 5; a[1] = 1;
    a[2] = 3; a[3] = 2;
    a[4] = 4;
    a.immersion(0);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[4], 5);
}

TEST(Dheap, can_insert_element) {
    d_heap a(3, 10);
    a[0] = 1; a[1] = 4;
    a[2] = 3; a[3] = 2;
    a[4] = 5;
    a.insert(3);
    EXPECT_EQ(a[1], 3);
    EXPECT_EQ(a[5], 4);
}