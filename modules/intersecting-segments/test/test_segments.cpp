// Copyright 2020 Kukushkina Ksenia

#include "include/segments.h"

#include <gtest/gtest.h>

TEST(Segment, can_create_segment) {
  // Arrange & Act & Assert
  ASSERT_NO_THROW(Segment(1, 2, 3, 4));
}
