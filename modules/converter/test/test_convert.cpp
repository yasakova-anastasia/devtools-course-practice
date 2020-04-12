// Copyright 2020 Andreev Sergey

#include <gtest/gtest.h>

#include "include/converter.h"

class ConvertTest : public ::testing::Test {};

TEST(ConvertTest, Convert_to_Kelvins)
{
// Arrange
double Cels = 5.0;
double Cels1 = 10.0;
double Cels2 = 15.0;

double Kelvins = 278.15;
double Kelvins1 = 283.15;
double Kelvins2 = 288.15;

Convert conv;
// Act

// Assert
ASSERT_EQ(Kelvins, conv.convert_to_Kelvins(Cels));
ASSERT_EQ(Kelvins1, conv.convert_to_Kelvins(Cels1));
ASSERT_EQ(Kelvins2, conv.convert_to_Kelvins(Cels2));
}

TEST(ConvertTest, Convert_to_Fahrenheit)
{
// Arrange
double Cels = 5.5;
double Cels1 = 10.0;
double Cels2 = 20.0;

double Fahrenheit = 41.9;
double Fahrenheit1 = 50.0;
double Fahrenheit2 = 68.0;

Convert conv;
// Act

// Assert
ASSERT_EQ(Fahrenheit, conv.convert_to_Fahrenheit(Cels));
ASSERT_EQ(Fahrenheit1, conv.convert_to_Fahrenheit(Cels1));
ASSERT_EQ(Fahrenheit2, conv.convert_to_Fahrenheit(Cels2));
}


TEST(ConvertTest, Convert_to_Newton)
{
// Arrange
double Cels = 5.0;
double Cels1 = 10.0;
double Cels2 = 25.0;

double Newton = 1.65;
double Newton1 = 3.3;
double Newton2 = 8.251;

double abs_error = 0.01;

Convert conv;
// Act

// Assert
ASSERT_DOUBLE_EQ(Newton, conv.convert_to_Newton(Cels));
ASSERT_DOUBLE_EQ(Newton1, conv.convert_to_Newton(Cels1));
ASSERT_NEAR(Newton2, conv.convert_to_Newton(Cels2), abs_error);
}


TEST(ConvertTest, Convert_wo_throw_Fahrenheit)
{
// Arrange
Convert conv;
double randnum = rand() % 5;

// Act

// Assert
ASSERT_NO_THROW(conv.convert_to_Fahrenheit(randnum));
}

TEST(ConvertTest, Convert_wo_throw_Kelvins)
{
// Arrange
Convert conv;
double randnum = rand() % 5;

// Act

// Assert
ASSERT_NO_THROW(conv.convert_to_Kelvins(randnum));
}

TEST(ConvertTest, Convert_wo_throw_Newton)
{
// Arrange
Convert conv;
double randnum = rand() % 5;

// Act

// Assert
ASSERT_NO_THROW(conv.convert_to_Newton(randnum));
}

TEST(ConvertTest, Convert_with_negative_num_Kelvins)
{
// Arrange
double Cels = -5.0;
double Kelvins = 268.15;
Convert conv;
// Act

// Assert
ASSERT_EQ(Kelvins, conv.convert_to_Kelvins(Cels));
}

TEST(ConvertTest, Convert_with_negative_num_Fahrenheit)
{
// Arrange
double Cels = -5.0;
double Fahrenheit = 23.0;
Convert conv;
// Act

// Assert
ASSERT_EQ(Fahrenheit, conv.convert_to_Fahrenheit(Cels));
}

TEST(ConvertTest, Convert_with_negative_num_Newton)
{
// Arrange
double Cels = -5.0;
double Newton = -1.65;
Convert conv;
// Act

// Assert
ASSERT_DOUBLE_EQ(Newton, conv.convert_to_Newton(Cels));
}
