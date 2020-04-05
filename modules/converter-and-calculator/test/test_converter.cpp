// Copyright 2020 Kornev Nikita

#include <gtest/gtest.h>

#include "include/converter.h"

TEST(ConverterTest, Can_Create_Converter) {
  // Arrange & Act
  converter conv;

  // Assert
  ASSERT_NO_THROW();
}

TEST(ConverterTest, Can_Convert_Decimal_To_Binary) {
  // Arrange
  converter conv;
  vector<bool> res, exp_res = { 1, 0, 0, 1, 0, 1 };

  // Act
  res = conv.convert_dec_to_bin(77);

  // Assert
  ASSERT_EQ(res, exp_res);
}

