// Copyright 2020 Mazur Daniil

#include <gtest/gtest.h>

#include <utility>

#include <numeric>

#include "../include/triangle_param.h"



TEST(TriangleParamTest, EmptyRest) {
  // Arrange

  // Act

  // Assert
  ASSERT_EQ(0, 0);
}

TEST(TriangleParamTest, DefaultComstructor) {
  // Arrange
  Triangle triag();
  // Act
  std::pair <double, double> a = triag().getTopA();
  // Assert
  ASSERT_EQ((0, 0), triag().getTopA());
  ASSERT_EQ((0, 0), triag().getTopB());
  ASSERT_EQ((0, 0), triag().getTopB());
  ASSERT_EQ(0, 0);
}
