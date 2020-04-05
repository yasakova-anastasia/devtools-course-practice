// Copyright 2020 Kornev Nikita

#include <gtest/gtest.h>

#include "include/converter.h"

TEST(ConverterTest, Can_Create_Converter) {
  // Arrange & Act
  converter conv;

  // Assert
  ASSERT_NO_THROW();
}

// Decimal to binary

TEST(ConverterTest, Can_Convert_Decimal_To_Binary) {
  // Arrange
  converter conv;
  int value = 77;
  vector<int> res, exp_res = { 1, 0, 0, 1, 1, 0, 1 };

  // Act
  res = conv.convert_dec_to_smaller(value, 2);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Decimal_Power_of_Two_To_Binary) {
  // Arrange
  converter conv;
  int value = 128;
  vector<int> res, exp_res = { 1, 0, 0, 0, 0, 0, 0, 0 };

  // Act
  res = conv.convert_dec_to_smaller(value, 2);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Big_Decimal_To_Binary) {
  // Arrange
  converter conv;
  int value = 24859708;
  vector<int> res, exp_res = { 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 };

  // Act
  res = conv.convert_dec_to_smaller(value, 2);

  // Assert
  ASSERT_EQ(res, exp_res);
}

// Binary to decimal

//TEST(ConverterTest, Can_Convert_Binary_To_Decimal) {
//  // Arrange
//  converter conv;
//  vector<bool> value = { 1, 1, 0, 1, 0, 0 };
//  int res, exp_res = 52;
//
//  // Act
//  res = conv.convert_bin_to_dec(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}
//
//TEST(ConverterTest, Can_Convert_Binary_Power_of_Two_To_Decimal) {
//  // Arrange
//  converter conv;
//  vector<bool> value = { 1, 0, 0, 0, 0, 0, 0, 0, 0 };
//  int res, exp_res = 256;
//
//  // Act
//  res = conv.convert_bin_to_dec(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}
//
//TEST(ConverterTest, Can_Convert_Big_Binary_To_Decimal) {
//  // Arrange
//  converter conv;
//  vector<bool> value = { 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 };
//  int res, exp_res = 24045045;
//
//  // Act
//  res = conv.convert_bin_to_dec(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}
//
//// Decimal to octal
//
//TEST(ConverterTest, Can_Convert_Decimal_To_Octal) {
//  // Arrange
//  converter conv;
//  int value = 47;
//  vector<int> res, exp_res = { 5, 7 };
//
//  // Act
//  res = conv.convert_dec_to_oct(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}
//
//TEST(ConverterTest, Can_Convert_Decimal_Power_of_Eight_To_Octal) {
//  // Arrange
//  converter conv;
//  int value = 512;
//  vector<int> res, exp_res = { 1, 0, 0, 0 };
//
//  // Act
//  res = conv.convert_dec_to_oct(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}
//
//TEST(ConverterTest, Can_Convert_Big_Decimal_To_Octal) {
//  // Arrange
//  converter conv;
//  int value = 65670567;
//  vector<int> res, exp_res = { 3, 7, 2, 4, 0, 6, 6, 4, 7 };
//
//  // Act
//  res = conv.convert_dec_to_oct(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}

// Octal to decimal

//TEST(ConverterTest, Can_Convert_Octal_To_Decimal) {
//  // Arrange
//  converter conv;
//  vector<int> value = { 3, 1 };
//  vector<int> res, exp_res = { 5, 7 };
//
//  // Act
//  res = conv.convert_dec_to_oct(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}

//TEST(ConverterTest, Can_Convert_Decimal_Power_of_Eight_To_Octal) {
//  // Arrange
//  converter conv;
//  int value = 512;
//  vector<int> res, exp_res = { 1, 0, 0, 0 };
//
//  // Act
//  res = conv.convert_dec_to_oct(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}
//
//TEST(ConverterTest, Can_Convert_Big_Decimal_To_Octal) {
//  // Arrange
//  converter conv;
//  int value = 65670567;
//  vector<int> res, exp_res = { 3, 7, 2, 4, 0, 6, 6, 4, 7 };
//
//  // Act
//  res = conv.convert_dec_to_oct(value);
//
//  // Assert
//  ASSERT_EQ(res, exp_res);
//}