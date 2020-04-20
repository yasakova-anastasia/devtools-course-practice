// Copyright 2020 Kukushkina Ksenia

#include <gtest/gtest.h>

#include "include/segments.h"

TEST(Segment, can_create_segment) {
  // Arrange & Act & Assert
  ASSERT_NO_THROW(Segment(1, 2, 3, 4));
}

TEST(Segment, area_correctness) {
  // Arrange
  Segment A(2, 7, 10, 3);

  // Act & Assert
  ASSERT_EQ(abs(A.area(8, 7)), 24);
}

TEST(Segment, area_sign) {
  // Arrange
  Segment A(1, 3, 7, 9);
  Segment A1(7, 9, 1, 3);

  // Act & Assert
  ASSERT_EQ(A1.area(5, 5) / A.area(5, 5), -1);
}
