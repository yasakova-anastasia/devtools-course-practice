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
    int arabicNum = 3;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("III", romanNum);
}

TEST(Test_roman_arabic_converter_6, Can_convert_4)
{
    //Arrange
    int arabicNum = 4;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("IV", romanNum);
}

TEST(Test_roman_arabic_converter_7, Can_convert_9)
{
    //Arrange
    int arabicNum = 9;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("IX", romanNum);
}

TEST(Test_roman_arabic_converter_8, Can_convert_40)
{
    //Arrange
    int arabicNum = 2;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("XL", romanNum);
}

TEST(Test_roman_arabic_converter_9, Can_convert_41)
{
    //Arrange
    int arabicNum = 41;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("XLI", romanNum);
}

TEST(Test_roman_arabic_converter_10, Can_convert_97)
{
    //Arrange
    int arabicNum = 97;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("XCVII", romanNum);
}

TEST(Test_roman_arabic_converter_11, Can_convert_471)
{
    //Arrange
    int arabicNum = 471;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("LDXXI", romanNum);
}

TEST(Test_roman_arabic_converter_12, Can_convert_2879)
{
    //Arrange
    int arabicNum = 2879;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("MMDCCCLXXIX", romanNum);
}

TEST(Test_roman_arabic_converter_12, Can_convert_3999)
{
    //Arrange
    int arabicNum = 3999;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("MMMCMXCIX", romanNum);
}

TEST(Test_roman_arabic_converter_12, Can_convert_not_roman)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "Error";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-1, arabicNum);
}
