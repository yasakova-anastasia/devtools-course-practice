// Copyright 2020 Isaev Ilya

#include <gtest/gtest.h>

#include "include/hashmap.h"

TEST(HashMapTest, can_create_hash_map) {
    ASSERT_NO_THROW(hashmap<>());
}

TEST(HashMapTest, can_create_hash_with_template_params) {
    ASSERT_NO_THROW((hashmap<int, double>()));
}

TEST(HashMapTest, hashmap_from_initializer_list) {
    ASSERT_NO_THROW((hashmap<int, double>({{1, 2.5}, {0, 3.4}})));
}

TEST(HashMapTest, can_get_elems_max_size) {
    hashmap<std::string, double> map(10);
    
    ASSERT_EQ(10, map.max_size());
}