// Copyright 2020 Myshkin Andrey

#include <gtest/gtest.h>

#include "include/AVL_Tree.h"

TEST(Myshkin_Andrey_AVL_Tree, Test_Can_Create_Node) {
    int key = 9;

    Node tmp(key);

    ASSERT_EQ(key, tmp.key);
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Constructor) {
    AVL_Tree tree;

    ASSERT_EQ(nullptr, tree.GetRootNode());
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Constructor_Height) {
    int key = 100;

    AVL_Tree tree;
    tree.InitRoot(key);

    ASSERT_EQ(1, tree.GetHeight(tree.GetRootNode()));
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Constructor_Key) {
    int key = 100;

    AVL_Tree tree;
    tree.InitRoot(key);

    ASSERT_EQ(key, tree.GetKey(tree.GetRootNode()));
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Constructor_Root_Key) {
    int key = 10;

    AVL_Tree tree;
    tree.InitRoot(key);
    int tmp = tree.GetRootKey();

    ASSERT_EQ(key, tmp);
}

TEST(Myshkin_Andrey_AVL_Tree, Test_Get_Left_And_Right_Subtree) {
    int key = 22;

    AVL_Tree tree;
    tree.InitRoot(key);

    EXPECT_EQ(nullptr, tree.GetLeftSubtree(tree.GetRootNode()));
    EXPECT_EQ(nullptr, tree.GetRightSubtree(tree.GetRootNode()));
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Small_Tree_Insert) {
    int KeyArrays[] = { 10, 20, 30, 40, 50 };
    int sts = 0;

    AVL_Tree tree;
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 5; i++) {
        tree.Insert(KeyArrays[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (tree.FindNode(KeyArrays[i]) == STATUS_OK) {
            sts = 0;
        } else {
            sts = -1;
        }
        EXPECT_EQ(0, sts);
    }
    // Status t = tree.FindNode(60);
    // if (t == 1) printf("MESSAGE: STATUS_WAR_NODE_NOT_FOUND\n");
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Small_Tree_War_Found) {
    int KeyArrays[] = { 150, 120, 90, 60, 30, 200 };
    int sts = 0;

    AVL_Tree tree;
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 6; i++) {
        tree.Insert(KeyArrays[i]);
    }

    for (int i = 0; i < 6; i++) {
        if (tree.FindNode(KeyArrays[i]) == STATUS_OK) {
            sts = 0;
        } else {
            sts = -1;
        }
        EXPECT_EQ(0, sts);
    }

    Status status = tree.FindNode(1000);
    EXPECT_EQ(1, status);
    // if (t == 1) printf("MESSAGE: STATUS_WAR_NODE_NOT_FOUND\n");
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Find_Max_Two_Nodes) {
    int KeyArrays[] = { 100, 90 };

    AVL_Tree tree;
    tree.InitRoot(KeyArrays[0]);

    tree.Insert(KeyArrays[1]);

    EXPECT_EQ(100, tree.FindMax());
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Find_Max_Eight_Nodes) {
    int KeyArrays[] = { 100, 90, 200, 400, 500, 300, 250, 330 };

    AVL_Tree tree;
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 8; i++) {
        tree.Insert(KeyArrays[i]);
    }

    EXPECT_EQ(500, tree.FindMax());
}


TEST(Myshkin_Andrey_AVL_Tree, Test_With_Find_Min) {
    int KeyArrays[] = { 100, 90, 110, 200, 80, 300 };

    AVL_Tree tree;
    tree.InitRoot(KeyArrays[0]);

    for (int i = 0; i < 6; i++) {
        tree.Insert(KeyArrays[i]);
    }

    EXPECT_EQ(80, tree.FindMin());
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Remove_Nodes) {
    int KeyArrays[] = { 300, 200, 100, 250, 90, 110 };
    int status = 0;

    AVL_Tree tree;
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 6; i++) {
        tree.Insert(KeyArrays[i]);
    }

    status = tree.Remove(250);
    status = tree.Remove(110);

    EXPECT_EQ(0, status);
}
