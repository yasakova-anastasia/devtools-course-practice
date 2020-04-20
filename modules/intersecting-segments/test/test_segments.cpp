// Copyright 2020 Kukushkina Ksenia

#include <gtest/gtest.h>

#include "include/segments.h"

TEST(Segment, can_create_segment) {
  // Arrange & Act & Assert
  ASSERT_NO_THROW(Segment(1, 2, 3, 4));
}
