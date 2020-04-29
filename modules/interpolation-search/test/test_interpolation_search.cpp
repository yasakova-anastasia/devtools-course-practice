// Copyright 2020 Golubeva Anna

#include <gtest/gtest.h>
#include <vector>
#include "include/interpolation_search.h"

TEST(InterpolationSearchTest, can_generate_vector) {
  // Arrange
  int size = 5;

  // Act
  std::vector<int> vec(5);

  // Assert
  ASSERT_NO_THROW(vec = generateRandomVector(size));
}

TEST(InterpolationSearchTest, throw_when_invalid_size) {
  // Arrange
  int size = -5;

  // Act && Assert
  ASSERT_ANY_THROW(std::vector<int> vec = generateRandomVector(size));
}

TEST(InterpolationSearchTest, throw_when_size_0) {
  // Arrange
  int size = 0;

  // Act && Assert
  ASSERT_ANY_THROW(std::vector<int> vec = generateRandomVector(size));
}

TEST(InterpolationSearchTest, partition_works) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_NO_THROW(int result = partition(&vec, 0, size - 1));
}

TEST(InterpolationSearchTest, throw_when_partition_boarders_are_negative) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&vec, -2, -3));
}

TEST(InterpolationSearchTest, throw_when_partition_right_boarder_is_negative) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&vec, -2, 5));
}

TEST(InterpolationSearchTest, throw_when_partition_left_boarder_is_negative) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&vec, 2, -3));
}

TEST(InterpolationSearchTest, throw_when_partition_boarders_min_greater_max) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&vec, 5, 2));
}

TEST(InterpolationSearchTest, partition_result_is_positive) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_GE(partition(&vec, 0, size - 1), 0);
}

TEST(InterpolationSearchTest, interpolation_search_works) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_NO_THROW(int result = interpolationSearch(&vec, vec[3]));
}

TEST(InterpolationSearchTest, interpolation_search_works_correctly) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  EXPECT_EQ(interpolationSearch(&vec, 3), 3);
}

TEST(InterpolationSearchTest, interpolation_search_value_exists) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_GE(interpolationSearch(&vec, vec[5]), 0);
}

TEST(InterpolationSearchTest, interpolation_search_value_does_not_exist) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GT(0, interpolationSearch(&vec, 100));
}

TEST(InterpolationSearchTest, returns_right) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GT(interpolationSearch(&vec, 9), 4);
}

TEST(InterpolationSearchTest, returns_left) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GE(4, interpolationSearch(&vec, 0));
}

TEST(InterpolationSearchTest, returns_left_double_check) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GE(interpolationSearch(&vec, 0), 0);
}

TEST(InterpolationSearchTest, right_value_changes) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Assert
  ASSERT_GE(interpolationSearch(&vec, 3), 0);
}

TEST(InterpolationSearchTest, right_value_changes_2) {
  // Arrange
  int size = 12;

  // Act
  std::vector<int> vec = {0, 1, 2, 3, 4, 51, 6, 7, 8, 90, 100, 11};

  // Assert
  ASSERT_GE(interpolationSearch(&vec, 51), 0);
}

TEST(InterpolationSearchTest, right_eq_left_val_exists) {
  // Arrange
  std::vector<int> vec = {0};

  // Act && Assert
  EXPECT_EQ(interpolationSearch(&vec, 0), 0);
}

TEST(InterpolationSearchTest, right_eq_left_val_does_not_exist) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = {5};

  // Assert
  EXPECT_EQ(interpolationSearch(&vec, 0), -1);
}
