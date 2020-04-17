// Copyright 2020 Myshkin Andrey

#include <gtest/gtest.h>

#include "include/AVL_Tree.h"

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Constructor) {
    
    AVL_Tree tree;

    ASSERT_EQ(nullptr, tree.GetRootNode());
}

//TEST(Myshkin_Andrey_AVL_Tree, Test_With_Constructor_Key) {
//
//    int key = 100;
//    
//    AVL_Tree tree;
//    tree.Insert(tree.GetRootNode(), key);
//
//    ASSERT_EQ(key, tree.GetRootKey());
//}

