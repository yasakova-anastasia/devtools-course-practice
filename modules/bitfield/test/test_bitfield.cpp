// Copyright 2020 Kudryashov Nikita 

// TODO: add extreme set / unset cases (0,7)

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
    EXPECT_ANY_THROW(a.set(out_of_bounds));
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Unset_Position) {
    // Arrange
    unsigned int size = 10;
    Bitfield a(size);
    
    // Act & Assert
    EXPECT_NO_THROW(a.unset(3));
}

TEST(Kudryashov_Nikita_BitfieldTest, Throw_Unset_Out_of_Bounds) {
    // Arrange
    unsigned int size = 10;
    unsigned int out_of_bounds = 12;
    Bitfield a(size);
    
    // Act & Assert
    EXPECT_ANY_THROW(a.unset(out_of_bounds));
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Get_Size) {
    // Arrange
    unsigned int size = 10;
    unsigned int expected_value = 10;
    Bitfield a(size);
    
    // Act & Assert
    EXPECT_EQ(expected_value, a.get_size());
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Get_Position_Value) {
    // Arrange
    unsigned int size = 10;
    Bitfield a(size);
    
    // Act & Assert
    EXPECT_NO_THROW(a.get(0));
}

TEST(Kudryashov_Nikita_BitfieldTest, Get_Returns_Right_Value) {
    // Arrange
    unsigned int size = 10;
    int expected_value = 1;
    Bitfield a(size);
    a.set(5);
    
    // Act & Assert
    EXPECT_EQ(expected_value, a.get(5));
}

TEST(Kudryashov_Nikita_BitfieldTest, Get_Returns_Only_One_Or_Zero) {
    // Arrange
    bool check = true;
    unsigned int size = 16;
    Bitfield a(size);
    a.set(1);
    a.set(5);
    a.set(7);
    
    // Act
    for (int i = 0; i < a.get_size(); i++) {
        if (a.get(i) != 1 && a.get(i) != 0) {
            check = false;
            break;
        }
    }
    
    // Assert
    EXPECT_EQ(check, true);
}

TEST(Kudryashov_Nikita_BitfieldTest, Bitfield_Creates_Empty) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    Bitfield a(size);
    
    // Act
    for (int i = 0; i < a.get_size(); i++) {
        if (a.get(i) != 0) {
            check = false;
            break;
        }
    }
    
    // Assert
    EXPECT_EQ(check, true);
}

TEST(Kudryashov_Nikita_BitfieldTest, Fill_Test) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    Bitfield a(size);
    
    // Act
    a.fill();
    
    for (int i = 0; i < a.get_size(); i++) {
        if (a.get(i) != 1) {
            check = false;
            break;
        }
    }
    
    // Assert
    EXPECT_EQ(check, true);
}

TEST(Kudryashov_Nikita_BitfieldTest, Clear_Test) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    Bitfield a(size);
    a.set(45);
    a.set(32);
    a.set(9);
    
    // Act
    a.clear();
    
    for (int i = 0; i < a.get_size(); i++) {
        if (a.get(i) != 0) {
            check = false;
            break;
        }
    }
    
    // Assert
    EXPECT_EQ(check, true);
}
