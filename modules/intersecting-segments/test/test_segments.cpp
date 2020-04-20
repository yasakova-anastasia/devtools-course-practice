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
