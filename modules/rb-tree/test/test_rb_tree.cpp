// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>

#include <random>
#include "include/rb_tree.h"

TEST(RBTreeTest, Construct_Node) {
    Node node(15);

    ASSERT_EQ(15, node.data);
}

TEST(RBTreeTest, Assign_Node) {
    Node n1(5), n2(3);

    n1 = n2;

    ASSERT_EQ(3, n2.data);
}

TEST(RBTreeTest, Equals_Node) {
    Node n1(3), n2(3);

    ASSERT_TRUE(n1 == n2);
}

TEST(RBTreeTest, Not_Equals_Node) {
    Node n1(3), n2(4);

    ASSERT_FALSE(n1 == n2);
}

TEST(RBTreeTest, Not_Equals_Node_Operator) {
    Node n1(3), n2(4);

    ASSERT_TRUE(n1 != n2);
}