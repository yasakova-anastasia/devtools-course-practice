// Copyright 2020 Vlasov Andrey

#include <gtest/gtest.h>

#include <string>

#include "include/leftist_heap.h"

TEST(NodeTest, Can_Create) {
  // Arrange
  Node node(7);

  // Act & Assert
  EXPECT_EQ(7, node.key);
  EXPECT_EQ(NULL, node.left);
  EXPECT_EQ(NULL, node.right);
}

TEST(NodeTest, Can_Merge) {
  // Arrange
  Node xHeap(2);
  Node yHeap(6);

  // Act
  Node* zHeap = Node::merge(&xHeap, &yHeap);

  // Assert
  EXPECT_EQ(2, zHeap->key);
  EXPECT_EQ(6, zHeap->left->key);
}

TEST(LeftistHeapTest, Can_Create_Is_Empty) {
  // Arrange
  LeftistHeap Heap;

  // Act & Assert
  EXPECT_TRUE(Heap.isEmpty());
}

TEST(LeftistHeapTest, Can_Copy_Head) {
  // Arrange
  LeftistHeap xHeap;

  // Act
  LeftistHeap yHeap = xHeap;

  // Assert
  EXPECT_TRUE(yHeap.isEmpty());
}
