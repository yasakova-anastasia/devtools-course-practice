// Copyright 2020 Maximova Irina

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/statistics.h"

TEST(StatisticsTest, Throw_When_The_Sum_Of_The_Probabilities_Is_Not_Equal_1) {
  // Arrange
  std::vector<double> probability = {0.3, 0.7, 0.1};

  // Act & Assert
  ASSERT_ANY_THROW(Statistics s(probability));
}

TEST(StatisticsTest, Can_Initialize_Probability) {
  // Arrange
  std::vector<double> probability = {0.2, 0.3, 0.5};

  // Act
  Statistics s(probability);

  // Assert
  ASSERT_EQ(s.getProbability(), probability);
}
