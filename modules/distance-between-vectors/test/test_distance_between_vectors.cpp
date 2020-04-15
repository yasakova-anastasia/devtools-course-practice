// Copyright 2020 Vladislav Golubev

#include <gtest/gtest.h>
#include <vector>
#include "include/distance_between_vectors.h"

class DistanceBetweenVectorsTest : public ::testing::Test {
 protected:
  double epsilon = 0.001;
};

TEST(DistanceBetweenVectorsTest, default_first_vec) {
  // Arrange
  std::vector<float> defaultVec(1);
  // Act
  Metrics metrics;

  // Assert
  EXPECT_EQ(metrics.getFirst(), defaultVec);
}

TEST(DistanceBetweenVectorsTest, default_sec_vec) {
  // Arrange
  std::vector<float> defaultVec(1);

  // Act
  Metrics metrics;

  // Assert
  EXPECT_EQ(metrics.getSecond(), defaultVec);
}

TEST(DistanceBetweenVectorsTest, create_with_two_vectors) {
  // Arrange
  std::vector<float> first{ 1.0, 2.0, 3.0 };
  std::vector<float> second{ 2.0, 3.0, 4.0 };

  // Act
  Metrics metrics(first, second);

  // Assert
  EXPECT_EQ(metrics.getFirst(), first);
  EXPECT_EQ(metrics.getSecond(), second);
}

TEST(DistanceBetweenVectorsTest, cannot_create_for_vec_of_different_div) {
  // Arrange
  int div1 = 5;
  int div2 = 10;
  std::vector<float> first(div1);
  std::vector<float> second(div2);

  // Act & Assert
  ASSERT_ANY_THROW(Metrics metrics(first, second));
}

TEST(DistanceBetweenVectorsTest, can_create_via_copying) {
  // Arrange
  std::vector<float> first{ 1.0, 2.0, 3.0 };
  std::vector<float> second{ 2.0, 3.0, 4.0 };
  Metrics metrics(first, second);

  // Act
  Metrics metricsCopy(metrics);

  // Assert
  EXPECT_EQ(metrics.getFirst(), metricsCopy.getFirst());
  EXPECT_EQ(metrics.getSecond(), metricsCopy.getSecond());
}

TEST(DistanceBetweenVectorsTest, can_set_first_vec) {
  // Arrange
  std::vector<float> first{ 1.0, 2.0, 3.0 };
  std::vector<float> newFirst{ 3.0, 2.0, 1.0 };
  std::vector<float> second{ 2.0, 3.0, 4.0 };
  Metrics metrics(first, second);

  // Act
  metrics.setFirst(newFirst);

  // Assert
  EXPECT_EQ(metrics.getFirst(), newFirst);
}

TEST(DistanceBetweenVectorsTest, can_set_second_vec) {
  // Arrange
  std::vector<float> first{ 1.0, 2.0, 3.0 };
  std::vector<float> second{ 2.0, 3.0, 4.0 };
  std::vector<float> newSecond{ 3.0, 2.0, 1.0 };
  Metrics metrics(first, second);

  // Act
  metrics.setSecond(newSecond);

  // Assert
  EXPECT_EQ(metrics.getSecond(), newSecond);
}

TEST(DistanceBetweenVectorsTest, cannot_set_fst_vec_of_another_div) {
  // Arrange
  std::vector<float> first{ 1.0, 2.0, 3.0 };
  std::vector<float> second{ 2.0, 3.0, 4.0 };
  std::vector<float> newFirst{ 3.0, 2.0 };
  Metrics metrics(first, second);

  // Act & Assert
  ASSERT_ANY_THROW(metrics.setFirst(newFirst));
}

TEST(DistanceBetweenVectorsTest, cannot_set_sec_vec_of_another_div) {
  // Arrange
  std::vector<float> first{ 1.0, 2.0, 3.0 };
  std::vector<float> second{ 2.0, 3.0, 4.0 };
  std::vector<float> newSecond{ 3.0, 2.0 };
  Metrics metrics(first, second);

  // Act & Assert
  ASSERT_ANY_THROW(metrics.setSecond(newSecond));
}
