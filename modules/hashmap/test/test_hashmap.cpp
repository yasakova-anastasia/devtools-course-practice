// Copyright 2020 Isaev Ilya

#include <gtest/gtest.h>

#include "include/hashmap.h"

TEST(HashMapTest, can_create_hash_map) {
    ASSERT_NO_THROW(hashmap());
}