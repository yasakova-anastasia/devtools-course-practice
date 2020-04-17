// Copyright 2020 Isaev Ilya

#include <gtest/gtest.h>

#include "include/hashmap.h"

TEST(HashMapTest, can_create_hash_map) {
    ASSERT_NO_THROW(hashmap<>());
}

TEST(HashMapTest, can_create_hash_with_template_params) {
    ASSERT_NO_THROW((hashmap<int, double>()));
}