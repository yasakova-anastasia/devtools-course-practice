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

TEST(SegmentTreeTest, Can_Create_Segment_Tree_With_Negative_Size) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(SegmentTree tree(-1));
}

TEST(SegmentTreeTest, Can_Create_Segment_Tree_With_Zero_Vector) {
    // Arrange
    std::vector <int> test = {};
    // Act & Assert
    EXPECT_ANY_THROW(SegmentTree tree(test));
}

TEST(SegmentTreeTest, Test_Function_Build_With_3_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3};
    // Act
    SegmentTree tree(test);
    std::vector <int> expected = {0, 6, 3, 3, 1, 2, 0, 0, 0, 0, 0, 0};
    std::vector <int> v = tree.Get();
    // Assert
    EXPECT_EQ(expected, v);
}

TEST(SegmentTreeTest, Test_Function_Build_With_4_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4};
    // Act
    SegmentTree tree(test);
    std::vector <int> expected = {0, 10, 3, 7, 1, 2, 3, 4, 0, 0, 0,
                                  0, 0, 0, 0, 0};
    std::vector <int> v = tree.Get();
    // Assert
    EXPECT_EQ(expected, v);
}

TEST(SegmentTreeTest, Test_Function_Build_With_50_zero_elements) {
    // Arrange
    int size = 50;
    std::vector <int> test(size, 0);
    // Act
    SegmentTree tree(test);
    std::vector <int> expected(4*size, 0);
    // Assert
    EXPECT_EQ(expected, tree.Get());
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_5_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5};
    // Act
    SegmentTree tree(test);
    // Arrange
    EXPECT_EQ(tree.sum(0, 2), 6);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_4_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4};
    // Act
    SegmentTree tree(test);
    // Arrange
    EXPECT_EQ(tree.sum(2, 3), 7);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_6_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6};
    // Act
    SegmentTree tree(test);
    // Arrange
    EXPECT_EQ(tree.sum(1, 4), 14);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_7_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6, 7};
    // Act
    SegmentTree tree(test);
    // Arrange
    EXPECT_EQ(tree.sum(4, 5), 11);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements) {
    // Arrange
    std::vector <int> test = {1, 2};
    // Act
    SegmentTree tree(test);
    // Arrange
    EXPECT_ANY_THROW(tree.sum(-1, 1));
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements_1) {
    // Arrange
    std::vector <int> test = {1, 2};
    // Act
    SegmentTree tree(test);
    // Arrange
    EXPECT_ANY_THROW(tree.sum(0, -1));
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements_2) {
    // Arrange
    std::vector <int> test = {1, 2};
    // Act
    SegmentTree tree(test);
    // Arrange
    EXPECT_ANY_THROW(tree.sum(1, 0));
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements_3) {
    // Arrange
    std::vector <int> test = {1, 2};
    // Act
    SegmentTree tree(test);
    // Arrange
    EXPECT_ANY_THROW(tree.sum(1, 3));
}
