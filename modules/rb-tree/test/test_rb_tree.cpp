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

TEST(RBTreeTest, Default_Constructor) {
    ASSERT_NO_THROW(RBTree{});
}

TEST(RBTreeTest, Construct_From_Node) {
    Node *node = new Node{};

    ASSERT_NO_THROW(RBTree{node});
}

TEST(RBTreeTest, Construct_From_Vector) {
    std::vector<int> vec{-3, 4, 1};

    ASSERT_NO_THROW(RBTree{vec});
}

TEST(RBTreeTest, Copy_Constructor) {
    std::vector<int> vec{-3, 4, 1};
    
    RBTree tree{vec};

    ASSERT_NO_THROW(RBTree{tree});
}

TEST(RBTreeTest, Can_Get_Root) {
    Node *node = new Node(2);

    RBTree tree{node};

    ASSERT_EQ(2, tree.GetRoot()->data);
}

TEST(RBTreeTest, Can_Find_Existing_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    ASSERT_TRUE(tree.find(14));
}

TEST(RBTreeTest, Can_Not_Find_Nonexistent_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    ASSERT_TRUE(tree.find(-14));
}

TEST(RBTreeTest, Can_Insert_New_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    Node *new_node = new Node(3);

    ASSERT_NO_THROW(tree.insert(new_node));
}

TEST(RBTreeTest, Can_Not_Insert_Existing_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    Node *new_node = new Node(-20);

    ASSERT_ANY_THROW(tree.insert(new_node));
}

TEST(RBTreeTest, Can_Remove_Existing_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    ASSERT_NO_THROW(tree.remove(-10));
}

TEST(RBTreeTest, Can_Not_Remove_Nonexistent_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    ASSERT_ANY_THROW(tree.remove(10));
}
