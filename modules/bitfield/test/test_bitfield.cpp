// Copyright 2020 Kudryashov Nikita 

#include "include/bitfield.h"

#include <gtest/gtest.h>

TEST(Kudryashov_Nikita_BitfieldTest, Can_Create_Bitfield_Without_Arguments) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(Bitfield a());
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Create_Bitfield_With_Arguments) {
    // Arrange
    unsigned int size = 10;
    
    // Act & Assert
    EXPECT_NO_THROW(Bitfield a(size));
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Set_Position) {
    // Arrange
    unsigned int size = 10;
    Bitfield a(size);
    
    // Act & Assert
    EXPECT_NO_THROW(a.set(0));
}

TEST(Kudryashov_Nikita_BitfieldTest, Throw_Set_Out_of_Bounds) {
    // Arrange
    unsigned int size = 10;
    unsigned int out_of_bounds = 11;
    Bitfield a(size);
    
    // Act & Assert
    EXPECT_ANY_THROW(a.set(11));
}
