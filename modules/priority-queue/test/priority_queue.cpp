// Copyright 2020 Egorov Danil

#include <gtest/gtest.h>

#include "include/priority_queue.h"

class PriorityQueueTest : public ::testing::Test {};

TEST_F(PriorityQueueTest, CanCreateDefaultNode) {
    // Act
    node n;

    // Assert
    EXPECT_EQ(n.key, 0);
    EXPECT_EQ(n.data, 0);
}

TEST_F(PriorityQueueTest, CanInsertNode) {
    // Arrange
    priority_queue pq;
    node n(1, 1342334);
    node* p_n;

    // Act
    pq.insert(n);
    p_n = pq.extract_minimum();

    // Assert
    EXPECT_EQ(p_n->data, n.data);
}

TEST_F(PriorityQueueTest, CheckEmptyReturnTrueIfEmpty) {
    // Arrange
    priority_queue pq;

    // Act
    bool res = pq.is_empty();

    // Assert
    EXPECT_EQ(res, true);
}

TEST_F(PriorityQueueTest, CheckEmptyReturnFalseIfEmpty) {
    // Arrange
    priority_queue pq;
    node n(1, 2);

    // Act
    pq.insert(n);
    bool res = pq.is_empty();

    // Assert
    EXPECT_EQ(res, false);
}

TEST_F(PriorityQueueTest, CanExtractMinimum) {
    // Arrange
    priority_queue pq;
    node n1(4, 4);
    node n2(1, 1);
    node n3(3, 3);
    node* p_n;

    // Act
    pq.insert(n1);
    pq.insert(n2);
    pq.insert(n3);
    p_n = pq.extract_minimum();

    // Assert
    EXPECT_EQ(p_n->key, n2.key);
}

TEST_F(PriorityQueueTest, CanExtractMaximum) {
    // Arrange
    priority_queue pq;
    node n1(2, 2);
    node n2(4, 4);
    node n3(3, 3);
    node* p_n;

    // Act
    pq.insert(n1);
    pq.insert(n2);
    pq.insert(n3);
    p_n = pq.extract_maximum();

    // Assert
    EXPECT_EQ(p_n->key, n2.key);
}

TEST_F(PriorityQueueTest, CanDeleteMinimum) {
    // Arrange
    priority_queue pq;
    node n1(4, 4);
    node n2(3, 3);
    node* p_n;

    // Act
    pq.insert(n1);
    pq.insert(n2);
    bool res = pq.deleteMin();
    p_n = pq.extract_minimum();

    // Assert
    EXPECT_EQ(res, true);
    EXPECT_EQ(p_n->key, n1.key);
}

TEST_F(PriorityQueueTest, CanDeleteMaximum) {
    // Arrange
    priority_queue pq;
    node n1(4, 4);
    node n2(3, 3);
    node* p_n;

    // Act
    pq.insert(n1);
    pq.insert(n2);
    bool res = pq.deleteMax();
    p_n = pq.extract_maximum();

    // Assert
    EXPECT_EQ(res, true);
    EXPECT_EQ(p_n->key, n2.key);
}

TEST_F(PriorityQueueTest, ReturnNullptrWhileExtractMinFromEmpty) {
    // Arrange
    priority_queue pq;
    node* p_n;

    // Act
    p_n = pq.extract_minimum();

    // Assert
    EXPECT_EQ(p_n, nullptr);
}

TEST_F(PriorityQueueTest, ReturnNullptrWhileExtractMaxFromEmpty) {
    // Arrange
    priority_queue pq;
    node* p_n;

    // Act
    p_n = pq.extract_maximum();

    // Assert
    EXPECT_EQ(p_n, nullptr);
}

TEST_F(PriorityQueueTest, ReturnFalseWhileDeleteMinFromEmpty) {
    // Arrange
    priority_queue pq;
    node* p_n;

    // Act
    bool res = pq.deleteMin();

    // Assert
    EXPECT_EQ(res, false);
}

TEST_F(PriorityQueueTest, ReturnFalseWhileDeleteMaxFromEmpty) {
    // Arrange
    priority_queue pq;
    node* p_n;

    // Act
    bool res = pq.deleteMax();

    // Assert
    EXPECT_EQ(res, false);
}
