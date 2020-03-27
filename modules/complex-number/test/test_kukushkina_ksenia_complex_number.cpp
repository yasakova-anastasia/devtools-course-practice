//Copyright 2020 Kukushkina Ksenia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kukushkina_Ksenia_ComplexNumberTest, imaginary_1) {
  //Arrange
  ComplexNumber a(0, 1);

  //Act
  ComplexNumber b = a * a;

  //Assert
  EXPECT_EQ(b.getRe(), -1);
  EXPECT_EQ(b.getIm(), 0);
}
