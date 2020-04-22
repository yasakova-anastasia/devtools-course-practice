// Copyright 2020 Yasakova Anastasia

#include <gtest/gtest.h>

#include "include/trees.h"


TEST(TreesTest, Constructor_Tree) {
    Tree tree(0);

    ASSERT_EQ(0, tree.GetDataRoot());
}

TEST(TreesTest, Add_Element) {
    Tree tree(0);

    tree.AddElem(5);

    ASSERT_EQ(2, tree.GetAmount());
}

TEST(TreesTest, Initializer_List_Constructor) {
    Tree tree1(0);
    tree1.AddElem(1);
    tree1.AddElem(2);
    tree1.AddElem(3);
    tree1.AddElem(4);

    Tree tree2 = { 0, 1, 2, 3, 4 };

    ASSERT_EQ(1, tree1 == tree2);
}

TEST(TreesTest, Equality) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality) {
    Tree tree1 = { 20, 10, 32, 5, 15, 27, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_FALSE(tree1 == tree2);
}

TEST(TreesTest, Add_Existing_Element) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    tree1.AddElem(5);

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Copy_Constructor_Tree) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };

	Tree tree2(tree1);

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Find_Elem_Return_Data) {
    Tree tree = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_TRUE(tree.FindElemData(10));
}

TEST(TreesTest, Not_Find_Elem) {
    Tree tree = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_FALSE(tree.FindElemData(17));
}

TEST(TreesTest, Find_Elem_Return_Node) {
    Tree tree = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_EQ(10, (tree.FindElemNode(10))->GetData());
}

TEST(TreesTest, Del_Last_Elem) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35, 32 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 32 };

    tree1.DelElem(35);

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Del_No_Last_Elem) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35, 22, 27 };
    Tree tree2 = { 20, 10, 27, 5, 15, 25, 35, 22 };

    tree1.DelElem(30);

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Del_Nonexistent_Elem) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    tree1.DelElem(40);

    ASSERT_TRUE(tree1 == tree2);
}
