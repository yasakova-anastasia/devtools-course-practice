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

TEST(StatisticsTest, Can_Create_Via_Copying) {
  // Arrange
  std::vector<double> probability = {0.2, 0.3, 0.5};
  Statistics s(probability);

  // Act
  Statistics copy_s(s);

  // Assert
  ASSERT_EQ(s.getProbability(), copy_s.getProbability());
}

TEST(StatisticsTest, Can_Set_Probability) {
  // Arrange
  std::vector<double> probability = {0.1, 0.3, 0.05, 0.55};
  Statistics s;

  // Act
  s.setProbability(probability);

  // Assert
  ASSERT_EQ(s.getProbability(), probability);
}

TEST(StatisticsTest, Can_Equate_Object) {
  // Arrange
  std::vector<double> probability = {0.1, 0.3, 0.05, 0.55};
  Statistics s(probability);
  Statistics equal_s;

  // Act
  equal_s = s;

  // Assert
  ASSERT_EQ(s.getProbability(), equal_s.getProbability());
}
