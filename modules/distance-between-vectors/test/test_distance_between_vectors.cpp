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