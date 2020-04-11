// Copyright 2020 Mazur Daniil

#include <gtest/gtest.h>

#include <utility>

#include <numeric>

#include "../include/triangle_param.h"



TEST(TriangleParamTest, EmptyRest) {
  // Arrange

  // Act

  // Assert
  ASSERT_EQ(0, 0);
}

TEST(TriangleParamTest, DefaultComstructor) {
  // Arrange
  Triangle triag{};
  std::pair<double, double> expexted(0, 0);
  // Act

  // Assert
  ASSERT_EQ(expexted, triag.getTopA());
  ASSERT_EQ(expexted, triag.getTopB());
  ASSERT_EQ(expexted, triag.getTopC());
}

TEST(TriangleParamTest, ComstructorByArgs) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act

  // Assert
  ASSERT_EQ(expextedA, triag.getTopA());
  ASSERT_EQ(expextedB, triag.getTopB());
  ASSERT_EQ(expextedC, triag.getTopC());
}

TEST(TriangleParamTest, ComstructorByCopy) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);
  Triangle triag2(triag);

  // Act

  // Assert
  ASSERT_EQ(triag.getTopA(), triag2.getTopA());
  ASSERT_EQ(triag.getTopB(), triag2.getTopB());
  ASSERT_EQ(triag.getTopC(), triag2.getTopC());
}

TEST(TriangleParamTest, SetTops) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag{};

  // Act
  triag.setTopA(expextedA);
  triag.setTopB(expextedB);
  triag.setTopC(expextedC);
  // Assert
  ASSERT_EQ(expextedA, triag.getTopA());
  ASSERT_EQ(expextedB, triag.getTopB());
  ASSERT_EQ(expextedC, triag.getTopC());
}

TEST(TriangleParamTest, AssignOverloaded) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act
  Triangle triag2 = triag;
  // Assert
  ASSERT_EQ(triag.getTopA(), triag2.getTopA());
  ASSERT_EQ(triag.getTopB(), triag2.getTopB());
  ASSERT_EQ(triag.getTopC(), triag2.getTopC());
}

TEST(TriangleParamTest, EqOverloaded) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act
  Triangle triag2 = triag;
  // Assert
  ASSERT_TRUE(triag == triag2);
}

TEST(TriangleParamTest, NoEqOverloaded) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act
  Triangle triag2{};
  // Assert
  ASSERT_FALSE(triag == triag2);
}

TEST(TriangleParamTest, Perimetr) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act
  double AB = triag.side(triag.getTopA(), triag.getTopB());
  double BC = triag.side(triag.getTopC(), triag.getTopB());
  double AC = triag.side(triag.getTopA(), triag.getTopC());
  // Assert
  ASSERT_EQ(triag.perimetr(), AB + BC + AC);
}

TEST(TriangleParamTest, Squere) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(4, 0);
  std::pair<double, double> expextedC(4, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act

  // Assert
  ASSERT_EQ(triag.square(), 6);
}
