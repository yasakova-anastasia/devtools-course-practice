// Copyright 2020 Maximova Irina

#include <gtest/gtest.h>

#include <string>

#include "include/statistics.h"

TEST(StatisticsTest, Trivial) {
  // Arrange
  int a = 2;
  int b = 2;
  int c = 4;

  // Act
  int expected_c = a + b;

  // Assert
  ASSERT_EQ(c, expected_c);
}
