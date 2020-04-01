// Copiright 2020 Vedrukov Pavel

#include <gtest/gtest.h>

#include <string>
#include "includes/roman-arabic-converter.h"

TEST(Test_roman_arabic_converter_1, Can_convert_zero)
{
    //Arrange
    int arabicNum = 0;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("InputNumOutOfRange", romanNum);
}

TEST(Test_roman_arabic_converter_2, Can_convert_4000)
{
    //Arrange
    int arabicNum = 4000;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("InputNumOutOfRange", romanNum);
}

TEST(Test_roman_arabic_converter_3, Can_convert_1)
{
    //Arrange
    int arabicNum = 4;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("I", romanNum);
}

TEST(Test_roman_arabic_converter_4, Can_convert_2)
{
    //Arrange
    int arabicNum = 2;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("II", romanNum);
}

TEST(Test_roman_arabic_converter_5, Can_convert_3)
{
    //Arrange
    int arabicNum = 2;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("III", romanNum);
}
