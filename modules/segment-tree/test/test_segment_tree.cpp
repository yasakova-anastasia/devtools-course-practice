// Copyright 2020 Devlikamov Vladislav

#include <gtest/gtest.h>

#include <include/segment-tree.h>
#include <vector>

TEST(SegmentTreeTest, Can_Create_Segment_Tree) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(SegmentTree tree(5));
}

TEST(SegmentTreeTest, Can_Create_Segment_Tree_With_Vector) {
    // Arrange
    std::vector <int> test = {1, 2, 3};
    // Act & Assert
    EXPECT_NO_THROW(SegmentTree tree(test));
}

TEST(SegmentTreeTest, Test_Function_Build) {
    // Arrange
    std::vector <int> test = {1, 2, 3};
    // Act
    SegmentTree tree(test);
    std::vector <int> expected = {0, 6, 3, 3, 1, 2, 0, 0, 0, 0, 0, 0};
    std::vector <int> v = tree.Get();
    // Assert
    EXPECT_EQ(expected, v);
}
