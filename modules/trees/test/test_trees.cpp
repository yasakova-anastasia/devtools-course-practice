// Copyright 2020 Yasakova Anastasia

#include <gtest/gtest.h>

#include "include/trees.h"



TEST(TreesTest, Constructor_TreeNode) {
    TreeNode* node = new TreeNode(4);

    ASSERT_EQ(4, node->GetData());
}

TEST(TreesTest, Copy_Constructor_TreeNode) {
    TreeNode* node1 = new TreeNode(4);

    TreeNode* node2(node1);

    ASSERT_EQ(4, node2->GetData());
}

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
    Tree tree1(10);
    tree1.AddElem(5);
    tree1.AddElem(15);
    tree1.AddElem(7);
    tree1.AddElem(20);

    Tree tree2 = { 10, 5, 15, 7, 20 };

    ASSERT_EQ(1, tree1 == tree2);
}

TEST(TreesTest, Equality) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality_Amount) {
    Tree tree1 = { 20, 10, 32, 5, 15, 27};
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_FALSE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality) {
    Tree tree1 = { 20, 10, 32, 5, 15, 27, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_FALSE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality_Structure_1) {
    Tree tree1 = { 20, 10, 30, 15, 27, 35, 17 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    ASSERT_FALSE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality_Structure_2) {
    Tree tree1 = { 20, 10, 30, 5, 15, 27, 35, 7 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35, 40 };

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

TEST(TreesTest, Del_Left_Leaf) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 35 };

    tree1.DelElem(25);

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Del_Right_Leaf) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25 };

    tree1.DelElem(35);

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Del_Node) {
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

TEST(TreesTest, Del_Root) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 15, 10, 30, 5, 25, 35 };

    tree1.DelElem(20);

    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Some_Tests_To_Del) {
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35, 22, 32, 21, 7, 17 };
    Tree tree2 = { 20, 10, 25, 5, 15, 22, 35 };

    tree1.DelElem(21);
    tree1.DelElem(32);
    tree1.DelElem(7);
    tree1.DelElem(17);
    tree1.DelElem(30);

    ASSERT_TRUE(tree1 == tree2);
}
