// Copyright 2020 Devlikamov Vladislav

#include <gtest/gtest.h>

#include <include/segment-tree.h>

TEST(SegmentTreeTest, CanCreateSegmentTree) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(SegmentTree tree(5));
}
