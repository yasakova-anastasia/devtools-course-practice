// Copyright 2020 Maximova Irina

#include <gtest/gtest.h>

#include <vector>

#include "include/statistics.h"

TEST(StatisticsTest, Throw_When_The_Sum_Probabilities_Not_Equal_Unit) {
  // Arrange
  std::vector<double> probability = {0.3, 0.7, 0.1};

  // Act & Assert
  ASSERT_ANY_THROW(Statistics s(probability));
}

TEST(StatisticsTest, Throw_When_Probability_Is_Negative) {
  // Arrange
  std::vector<double> probability = {0.3, -0.7, 0.1};

  // Act & Assert
  ASSERT_ANY_THROW(Statistics s(probability));
}

TEST(StatisticsTest, Can_Initialize_Probability) {
  // Arrange
  std::vector<double> probability = {0.2, 0.3, 0.5};

  // Act
  Statistics s(probability);

  // Assert
  ASSERT_EQ(s.getProbability(), probability);
}

TEST(StatisticsTest, Can_Create_Via_Copying) {
  // Arrange
  std::vector<double> probability = {0.2, 0.3, 0.5};
  Statistics s(probability);

  // Act
  Statistics copy_s(s);

  // Assert
  ASSERT_EQ(s.getProbability(), copy_s.getProbability());
}

TEST(StatisticsTest, Can_Set_Probability) {
  // Arrange
  std::vector<double> probability = {0.1, 0.3, 0.05, 0.55};
  Statistics s;

  // Act
  s.setProbability(probability);

  // Assert
  ASSERT_EQ(s.getProbability(), probability);
}

TEST(StatisticsTest, Can_Equate_Object) {
  // Arrange
  std::vector<double> probability = {0.1, 0.3, 0.05, 0.55};
  Statistics s(probability);
  Statistics equal_s;

  // Act
  equal_s = s;

  // Assert
  ASSERT_EQ(s.getProbability(), equal_s.getProbability());
}

TEST(StatisticsTest, Get_Expected_Value) {
  // Arrange
  Statistics s({0.1, 0.3, 0.05, 0.55});
  double exp_val = 2.05;

  // Act
  double exp_val_s = s.expectedValue();

  // Assert
  ASSERT_NEAR(exp_val, exp_val_s, 0.001);
}

TEST(StatisticsTest, Get_Dispersion_Value) {
  // Arrange
  Statistics s({0.1, 0.3, 0.05, 0.55});
  double disp_val = 1.2475;

  // Act
  double disp_val_s = s.dispersion();

  // Assert
  ASSERT_NEAR(disp_val, disp_val_s, 0.001);
}

TEST(StatisticsTest, Init_Order_Of_Zero_Order_Equal_Unit) {
  // Arrange
  Statistics s({0.1, 0.3, 0.05, 0.55});
  int order = 0;
  double a = 4;
  double exp_disp_val = 1;

  // Act
  double disp_val = s.moment(order, a);

  // Assert
  ASSERT_NEAR(exp_disp_val, disp_val, 0.001);
}

TEST(StatisticsTest, Get_Fifth_Order_Moment_of_Random_Variable) {
  // Arrange
  Statistics s({0.1, 0.3, 0.05, 0.55});
  double disp_val = 17.55;
  double a = 1.;
  int order = 5;

  // Act
  double disp_val_s = s.moment(order, a);

  // Assert
  ASSERT_NEAR(disp_val, disp_val_s, 0.001);
}

TEST(StatisticsTest, Throw_When_Order_Is_Negative) {
  // Arrange
  Statistics s({0.1, 0.3, 0.05, 0.55});
  double exp_val = s.expectedValue();
  int order = -2;

  // Act & Assert
  ASSERT_ANY_THROW(s.moment(order, exp_val));
}

TEST(StatisticsTest, Probabilities_Is_Equal_To_Itself) {
  // Arrange
  Statistics s({0.1, 0.3, 0.6});

  // Act & Assert
  EXPECT_TRUE(s == s);
}

TEST(StatisticsTest, True_Equal_For_Equal_Probability) {
  // Arrange
  Statistics s1({0.1, 0.9});
  Statistics s2({0.1, 0.9});

  // Act & Assert
  ASSERT_EQ(s1, s2);
}

TEST(StatisticsTest, False_Equal_For_Different_Probability) {
  // Arrange
  Statistics s1({0.1, 0.9});
  Statistics s2({0.9, 0.1});

  // Act & Assert
  ASSERT_FALSE(s1 == s2);
}

TEST(StatisticsTest, True_Different_For_Different_Probability) {
  // Arrange
  Statistics s1({0.1, 0.9});
  Statistics s2({0.9, 0.1});

  // Act & Assert
  ASSERT_TRUE(s1 != s2);
}

TEST(StatisticsTest, False_Different_For_Equal_Probability) {
  // Arrange
  Statistics s1({0.1, 0.9});
  Statistics s2({0.1, 0.9});

  // Act & Assert
  ASSERT_FALSE(s1 != s2);
}
