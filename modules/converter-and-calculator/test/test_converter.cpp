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
  vector<int> value = { 7, 7 };
  vector<int> res, exp_res = { 1, 0, 0, 1, 1, 0, 1 };

  // Act
  res = conv.convert(value, 10, 2);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Decimal_Power_of_Two_To_Binary) {
  // Arrange
  converter conv;
  vector<int> value = { 1, 2, 8 };
  vector<int> res, exp_res = { 1, 0, 0, 0, 0, 0, 0, 0 };

  // Act
  res = conv.convert(value, 10, 2);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Big_Decimal_To_Binary) {
  // Arrange
  converter conv;
  vector<int> value = { 2, 4, 8, 5, 9, 7, 0, 8 };
  vector<int> res, exp_res = { 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 };

  // Act
  res = conv.convert(value, 10, 2);

  // Assert
  ASSERT_EQ(res, exp_res);
}

// Binary to decimal

TEST(ConverterTest, Can_Convert_Binary_To_Decimal) {
  // Arrange
  converter conv;
  vector<int> value = { 1, 1, 0, 1, 0, 0 }, res, exp_res = { 5, 2 };

  // Act
  res = conv.convert(value, 2, 10);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Binary_Power_of_Two_To_Decimal) {
  // Arrange
  converter conv;
  vector<int> value = { 1, 0, 0, 0, 0, 0, 0, 0, 0 }, res, exp_res = { 2, 5, 6 };

  // Act
  res = conv.convert(value, 2, 10);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Big_Binary_To_Decimal) {
  // Arrange
  converter conv;
  vector<int> value = { 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 }, res, 
    exp_res = { 2, 4, 0, 4, 5, 0, 4, 5 };

  // Act
  res = conv.convert(value, 2, 10);

  // Assert
  ASSERT_EQ(res, exp_res);
}

// Decimal to octal

TEST(ConverterTest, Can_Convert_Decimal_To_Octal) {
  // Arrange
  converter conv;
  vector<int> value = { 4, 7 };
  vector<int> res, exp_res = { 5, 7 };

  // Act
  res = conv.convert(value, 10, 8);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Decimal_Power_of_Eight_To_Octal) {
  // Arrange
  converter conv;
  vector<int> value = { 5, 1, 2 };
  vector<int> res, exp_res = { 1, 0, 0, 0 };

  // Act
  res = conv.convert(value, 10, 8);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Big_Decimal_To_Octal) {
  // Arrange
  converter conv;
  vector<int> value = { 6, 5, 6, 7, 0, 5, 6, 7 };
  vector<int> res, exp_res = { 3, 7, 2, 4, 0, 6, 6, 4, 7 };

  // Act
  res = conv.convert(value, 10, 8);

  // Assert
  ASSERT_EQ(res, exp_res);
}

// Octal to decimal

TEST(ConverterTest, Can_Convert_Octal_To_Decimal) {
  // Arrange
  converter conv;
  vector<int> value = { 1, 4, 5 }, res, exp_res = { 1, 0, 1 };

  // Act
  res = conv.convert(value, 8, 10);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Octal_Power_of_Eight_To_Decimal) {
  // Arrange
  converter conv;
  vector<int> value = { 1, 0, 0 }, res, exp_res = { 6, 4 };

  // Act
  res = conv.convert(value, 8, 10);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Big_Octal_To_Decimal) {
  // Arrange
  converter conv;
  vector<int> value = { 3, 7, 2, 4, 0, 6, 6, 4, 7 }, res, exp_res = { 6, 5, 6, 7, 0, 5, 6, 7 };

  // Act
  res = conv.convert(value, 8, 10);

  // Assert
  ASSERT_EQ(res, exp_res);
}

// Decimal to hexadecimal

TEST(ConverterTest, Can_Convert_Decimal_To_Hexadecimal) {
  // Arrange
  converter conv;
  int value = 158;
  vector<char> res, exp_res = { '9', 'E' };

  // Act
  res = conv.convert_dec_to_hex(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Decimal_Power_Of_Sixteen_To_Hexadecimal) {
  // Arrange
  converter conv;
  int value = 4096;
  vector<char> res, exp_res = { '1', '0', '0', '0' };

  // Act
  res = conv.convert_dec_to_hex(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Big_Decimal_To_Hex) {
  // Arrange
  converter conv;
  int value = 23534565;
  vector<char> res, exp_res = { '1', '6', '7', '1', 'B', 'E', '5' };

  // Act
  res = conv.convert_dec_to_hex(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

// Hexadecimal to decimal

TEST(ConverterTest, Can_Convert_Hexadecimal_To_Decimal) {
  // Arrange
  converter conv;
  vector<char> value = { '3', 'A', 'B' };
  int res, exp_res = 939;

  // Act
  res = conv.convert_hex_to_dec(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Hexadecimal_Power_Of_Sixteen_To_Decimal) {
  // Arrange
  converter conv;
  vector<char> value = { '1', '0', '0', '0', '0' };
  int res, exp_res = 65536;

  // Act
  res = conv.convert_hex_to_dec(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Big_Hexadecimal_To_Decimal) {
  // Arrange
  converter conv;
  vector<char> value = { '5', 'C', 'B', 'D', '8','B', 'C' };
  int res, exp_res = 97245372;

  // Act
  res = conv.convert_hex_to_dec(value);

  // Assert
  ASSERT_EQ(res, exp_res);
}

// Binary to octal

TEST(ConverterTest, Can_Convert_Binary_To_Octal_1) {
  // Arrange
  converter conv;
  vector<int> value = { 1, 1, 0, 1, 0, 0 }, exp_res = { 6, 4 }, res;


  // Act
  res = conv.convert(value, 2, 8);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Binary_To_Octal_2) {
  // Arrange
  converter conv;
  vector<int> value = { 1, 0, 1, 0, 0, 1, 1 }, exp_res = { 1, 2, 3 }, res;

  // Act
  res = conv.convert(value, 2, 8);

  // Assert
  ASSERT_EQ(res, exp_res);
}

// Octal to Binary

TEST(ConverterTest, Can_Convert_Octal_To_Binary_1) {
  // Arrange
  converter conv;
  vector<int> value = { 6, 5, 4 }, exp_res = { 1, 1, 0, 1, 0, 1, 1, 0, 0 }, res;


  // Act
  res = conv.convert(value, 8, 2);

  // Assert
  ASSERT_EQ(res, exp_res);
}

TEST(ConverterTest, Can_Convert_Octal_To_Binary_2) {
  // Arrange
  converter conv;
  vector<int> value = { 7, 4, 3 }, exp_res = { 1, 1, 1, 1, 0, 0, 0, 1, 1 }, res;

  // Act
  res = conv.convert(value, 8, 2);

  // Assert
  ASSERT_EQ(res, exp_res);
}

