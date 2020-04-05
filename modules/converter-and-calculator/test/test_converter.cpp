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
  int value = 77;
  vector<bool> res, exp_res = { 1, 0, 0, 1, 1, 0, 1 };

  // Act
  res = conv.convert_dec_to_bin(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Another_Decimal_To_Binary) {
  // Arrange
  converter conv;
  int value = 66;
  vector<bool> res, exp_res = { 1, 0, 0, 0, 0, 1, 0 };

  // Act
  res = conv.convert_dec_to_bin(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Decimal_Power_of_Two_To_Binary) {
  // Arrange
  converter conv;
  int value = 128;
  vector<bool> res, exp_res = { 1, 0, 0, 0, 0, 0, 0, 0 };

  // Act
  res = conv.convert_dec_to_bin(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Big_Decimal_To_Binary) {
  // Arrange
  converter conv;
  int value = 24859708;
  vector<bool> res, exp_res = { 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 };

  // Act
  res = conv.convert_dec_to_bin(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}
