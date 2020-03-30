// Copyright 2020 Maximova Irina

#include <gtest/gtest.h>

#include <map>
#include <vector>

#include "include/statistics.h"

class StatisticsTest : public ::testing::Test {
 protected:
  double epsilon = 0.001;
};

TEST_F(StatisticsTest, Can_Initialize_Rand_Variable) {
  // Arrange
  std::vector<int> value = {0, 1, 2};
  std::vector<double> probability = {0.2, 0.3, 0.5};
  std::map<int, double> rand_var = {{0, 0.2}, {1, 0.3}, {2, 0.5}};

  // Act
  Statistics s(rand_var);

  // Assert
  ASSERT_EQ(s.getValue(), value);
  ASSERT_EQ(s.getProbability(), probability);
}

TEST_F(StatisticsTest, Throw_When_The_Sum_Probabilities_Not_Equal_Unit) {
  // Arrange
  std::map<int, double> rand_var = {{0, 0.7}, {1, 0.9}};

  // Act & Assert
  ASSERT_ANY_THROW(Statistics s(rand_var));
}

TEST_F(StatisticsTest, Throw_When_Probability_Is_Negative) {
  // Arrange
  std::map<int, double> rand_var = {{0, 0.2}, {1, -0.3}};

  // Act & Assert
  ASSERT_ANY_THROW(Statistics s(rand_var));
}

TEST_F(StatisticsTest, Throw_When_Value_Is_Repeated) {
  // Arrange
  std::map<int, double> rand_var = {{0, 0.2}, {0, 0.8}};

  // Act & Assert
  ASSERT_ANY_THROW(Statistics s(rand_var));
}

TEST_F(StatisticsTest, Can_Create_Via_Copying) {
  // Arrange
  Statistics s({{0, 0.4}, {1, 0.6}});

  // Act
  Statistics copy_s(s);

  // Assert
  ASSERT_EQ(s.getRandomVar(), copy_s.getRandomVar());
}

TEST_F(StatisticsTest, Can_Set_Random_Variable) {
  // Arrange
  Statistics s;
  std::map<int, double> rand_var = {{0, 0.1}, {1, 0.3}, {2, 0.6}};

  // Act
  s.setRandomVar(rand_var);

  // Assert
  ASSERT_EQ(s.getRandomVar(), rand_var);
}

TEST_F(StatisticsTest, Can_Equate_Object) {
  // Arrange
  Statistics s({{0, 0.1}, {1, 0.3}, {2, 0.6}});
  Statistics equal_s;

  // Act
  equal_s = s;

  // Assert
  ASSERT_EQ(s.getRandomVar(), equal_s.getRandomVar());
}

TEST_F(StatisticsTest, Get_Expected_Value) {
  // Arrange
  Statistics s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  double exp_val = 2.05;

  // Act
  double exp_val_s = s.expectedValue();

  // Assert
  ASSERT_NEAR(exp_val, exp_val_s, StatisticsTest::epsilon);
}

TEST_F(StatisticsTest, Throw_When_Call_Expected_Value_But_Data_Is_Empty) {
  // Arrange
  Statistics s;

  // Act & Assert
  ASSERT_ANY_THROW(s.expectedValue());
}

TEST_F(StatisticsTest, Get_Fifth_Order_Moment_of_Random_Variable) {
  // Arrange
  Statistics s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  double disp_val = 17.55;
  double a = 1.;
  int order = 5;

  // Act
  double disp_val_s = s.moment(order, a);

  // Assert
  ASSERT_NEAR(disp_val, disp_val_s, StatisticsTest::epsilon);
}

TEST_F(StatisticsTest, Zero_Order_Moment_Equal_Unit) {
  // Arrange
  Statistics s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  int order = 0;
  double a = 4;
  double exp_disp_val = 1;

  // Act
  double disp_val = s.moment(order, a);

  // Assert
  ASSERT_NEAR(exp_disp_val, disp_val, StatisticsTest::epsilon);
}

TEST_F(StatisticsTest, Throw_When_Call_Moment_But_Data_Is_Empty) {
  // Arrange
  Statistics s;
  double a = 1.;
  int order = 5;

  // Act & Assert
  ASSERT_ANY_THROW(s.moment(order, a));
}

TEST_F(StatisticsTest, Throw_When_Order_Is_Negative) {
  // Arrange
  Statistics s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  double exp_val = s.expectedValue();
  int order = -2;

  // Act & Assert
  ASSERT_ANY_THROW(s.moment(order, exp_val));
}

TEST_F(StatisticsTest, Get_Dispersion_Value) {
  // Arrange
  Statistics s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  double disp_val = 1.2475;

  // Act
  double disp_val_s = s.dispersion();

  // Assert
  ASSERT_NEAR(disp_val, disp_val_s, StatisticsTest::epsilon);
}

TEST_F(StatisticsTest, Random_Variable_Is_Equal_To_Itself) {
  // Arrange
  Statistics s({{2, 0.9}, {4, 0.1}});

  // Act & Assert
  EXPECT_TRUE(s == s);
}

TEST_F(StatisticsTest, Equal_Random_Variable_Are_Equal) {
  // Arrange
  Statistics s1({{2, 0.9}, {4, 0.1}});
  Statistics s2({{2, 0.9}, {4, 0.1}});

  // Act & Assert
  EXPECT_EQ(s1, s2);
}

TEST_F(StatisticsTest, Equal_Random_Variables_With_Different_Position_Values) {
  // Arrange
  Statistics s1({{2, 0.9}, {4, 0.1}});
  Statistics s2({{4, 0.1}, {2, 0.9}});

  // Act & Assert
  EXPECT_EQ(s1, s2);
}

TEST_F(StatisticsTest, Different_Random_Variable_Not_Equal) {
  // Arrange
  Statistics s1({{2, 0.9}, {4, 0.1}});
  Statistics s2({{1, 0.6}, {-4, 0.4}});

  // Act & Assert
  EXPECT_TRUE(s1 != s2);
}
