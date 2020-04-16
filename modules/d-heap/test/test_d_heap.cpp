// Copyright 2020 Antipin Alexander

#include <gtest/gtest.h>
#include <algorithm>
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

TEST(Dheap, is_creating_d_heap_with_two_parameters_correct_2) {
    d_heap a(3, 10);
    EXPECT_EQ(a.getCount(), 0);
}

TEST(Dheap, is_creating_d_heap_with_two_parameters_correct_3) {
    d_heap a(3, 10);
    EXPECT_EQ(a.getSize(), 10);
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

TEST(Dheap, is_creating_d_heap_from_copy_correct_1) {
    d_heap copy(3, 10);
    d_heap a(copy);
    EXPECT_EQ(a.getD(), 3);
}

TEST(Dheap, is_creating_d_heap_from_copy_correct_2) {
    d_heap copy(3, 10);
    d_heap a(copy);
    EXPECT_EQ(a.getCount(), 0);
}

TEST(Dheap, is_creating_d_heap_from_copy_correct_3) {
    d_heap copy(3, 10);
    d_heap a(copy);
    EXPECT_EQ(a.getSize(), 10);
}

TEST(Dheap, is_creating_d_heap_from_copy_return_correct_values) {
    d_heap copy(3, 10);
    d_heap a(copy);
    size_t i = -1;
    EXPECT_EQ(a[0], i);
}

TEST(Dheap, can_insert_element_without_throw) {
    d_heap a(3, 10);
    ASSERT_NO_THROW(a.insert(2));
}

TEST(Dheap, can_insert_element) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    EXPECT_EQ(a[0], 2);
    EXPECT_EQ(a[1], 4);
}

TEST(Dheap, is_insert_element_with_memory_relocate_correct) {
    d_heap a(3, 4);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    a.insert(5);
    ASSERT_NO_THROW(a.insert(6));
}

TEST(Dheap, can_return_first_child_without_throws) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    ASSERT_NO_THROW(a.firstChild(0));
}

TEST(Dheap, can_return_first_child_1) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    EXPECT_EQ(a.firstChild(0), 1);
}

TEST(Dheap, can_return_first_child_2) {
    d_heap a(3, 10);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);
    EXPECT_EQ(a.firstChild(1), 4);
}

TEST(Dheap, can_return_last_child_without_throws) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    ASSERT_NO_THROW(a.lastChild(0));
}

TEST(Dheap, can_return_last_child_1) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    EXPECT_EQ(a.lastChild(0), 3);
}

TEST(Dheap, can_return_last_child_2) {
    d_heap a(3, 6);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);
    EXPECT_EQ(a.lastChild(1), 5);
}

TEST(Dheap, can_return_min_child_without_throws) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    ASSERT_NO_THROW(a.minChild(0));
}

TEST(Dheap, can_return_min_child_1) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    EXPECT_EQ(a.minChild(0), 2);
}

TEST(Dheap, can_return_min_child_2) {
    d_heap a(3, 6);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);
    EXPECT_EQ(a.minChild(1), 4);
}

TEST(Dheap, can_return_father_without_throws) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    ASSERT_NO_THROW(a.father(2));
}

TEST(Dheap, can_return_father_1) {
    d_heap a(3, 10);
    a.insert(2);
    a.insert(4);
    a.insert(3);
    EXPECT_EQ(a.father(2), 0);
}

TEST(Dheap, can_return_father_2) {
    d_heap a(3, 6);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);
    EXPECT_EQ(a.father(5), 1);
}

TEST(Dheap, can_ascent_element_without_throws) {
    d_heap a(3, 10);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(1);
    ASSERT_NO_THROW(a.ascent(4));
}

TEST(Dheap, can_ascent_element_1) {
    d_heap a(3, 10);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(1); a.ascent(4);
    EXPECT_EQ(a[0], 1);
}

TEST(Dheap, can_ascent_element_2) {
    d_heap a(3, 10);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(1);
    EXPECT_EQ(a[0], 1);
}

TEST(Dheap, can_immersion_element_without_throws) {
    d_heap a(3, 10);
    a.insert(5); a.insert(1);
    a.insert(3); a.insert(2);
    a.insert(4);
    ASSERT_NO_THROW(a.immersion(0));
}

TEST(Dheap, can_immersion_element_1) {
    d_heap a(3, 10);
    a.insert(5); a.insert(1);
    a.insert(3); a.insert(2);
    a.insert(4);
    a.immersion(0);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[4], 5);
}

TEST(Dheap, can_immersion_element_2) {
    d_heap a(3, 10);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(1);
    a.immersion(1);
    EXPECT_EQ(a[5], 4);
}

TEST(Dheap, can_delete_element_without_throws) {
    d_heap a(3, 10);
    a.insert(1); a.insert(4);
    a.insert(3); a.insert(2);
    a.insert(5);
    ASSERT_NO_THROW(a.del(0));
}

TEST(Dheap, can_delete_element_1) {
    d_heap a(3, 10);
    a.insert(1); a.insert(4);
    a.insert(3); a.insert(2);
    a.insert(5);
    a.del(0);
    EXPECT_EQ(a[0], 2);
    EXPECT_EQ(a[3], 5);
}

TEST(Dheap, can_delete_element_2) {
    d_heap a(3, 10);
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(1);
    a.del(5);
    EXPECT_EQ(a[1], 2);
}

TEST(Dheap, can_decrease_element_key_without_throws) {
    d_heap a(3, 10);
    a.insert(1); a.insert(4);
    a.insert(3); a.insert(2);
    a.insert(5);
    ASSERT_NO_THROW(a.key_decrease(4, 4));
}

TEST(Dheap, can_decrease_element_keyt_1) {
    d_heap a(3, 10);
    a.insert(1); a.insert(4);
    a.insert(3); a.insert(2);
    a.insert(5);
    a.key_decrease(4, 4);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 1);
}

TEST(Dheap, can_decrease_element_key_2) {
    d_heap a(3, 10);
    a.insert(2), a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(1);
    a.key_decrease(4, 2);
    EXPECT_EQ(a[4], 3);
}
