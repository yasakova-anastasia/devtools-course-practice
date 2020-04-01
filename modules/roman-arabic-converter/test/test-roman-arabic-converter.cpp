// Copiright 2020 Vedrukov Pavel

#include <gtest/gtest.h>

#include <string>
#include "includes/roman-arabic-converter.h"

TEST(Test_roman_arabic_converter_1, Can_convert_zero)
{
    //Arrange
    short int arabicNum = 0;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("InputNumOutOfRange", romanNum);
}

TEST(Test_roman_arabic_converter_2, Can_convert_4000)
{
    //Arrange
    short int arabicNum = 4000;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("InputNumOutOfRange", romanNum);
}

TEST(Test_roman_arabic_converter_3, Can_convert_1)
{
    //Arrange
    short int arabicNum = 4;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("I", romanNum);
}

TEST(Test_roman_arabic_converter_4, Can_convert_2)
{
    //Arrange
    short int arabicNum = 2;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("II", romanNum);
}

TEST(Test_roman_arabic_converter_5, Can_convert_3)
{
    //Arrange
    short int arabicNum = 3;
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
    short int arabicNum = 9;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("IX", romanNum);
}

TEST(Test_roman_arabic_converter_8, Can_convert_40)
{
    //Arrange
    short int arabicNum = 2;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("XL", romanNum);
}

TEST(Test_roman_arabic_converter_9, Can_convert_41)
{
    //Arrange
    short int arabicNum = 41;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("XLI", romanNum);
}

TEST(Test_roman_arabic_converter_10, Can_convert_97)
{
    //Arrange
    short int arabicNum = 97;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("XCVII", romanNum);
}

TEST(Test_roman_arabic_converter_11, Can_convert_471)
{
    //Arrange
    short int arabicNum = 471;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("LDXXI", romanNum);
}

TEST(Test_roman_arabic_converter_12, Can_convert_2879)
{
    //Arrange
    short int arabicNum = 2879;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("MMDCCCLXXIX", romanNum);
}

TEST(Test_roman_arabic_converter_13, Can_convert_3999)
{
    //Arrange
    short int arabicNum = 3999;
    std::string romanNum;
    
    //Act
    romanNum.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_STREQ("MMMCMXCIX", romanNum);
}

TEST(Test_roman_arabic_converter_14, Can_convert_not_roman)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "Error";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-1, arabicNum);
}

TEST(Test_roman_arabic_converter_15, Can_convert_IIII)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "IIII";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_16, Can_convert_VV)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "VV";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_17, Can_convert_XXXX)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "XXXX";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_18, Can_convert_LL)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "LL";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_19, Can_convert_CCCC)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "CCCC";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_20, Can_convert_DD)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "DD";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_21, Can_convert_MMMM)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "MMMM";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_22, Can_convert_IV)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "IV";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(4, arabicNum);
}

TEST(Test_roman_arabic_converter_23, Can_convert_IX)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "IX";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(9, arabicNum);
}

TEST(Test_roman_arabic_converter_24, Can_convert_XL)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "XL";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(40, arabicNum);
}

TEST(Test_roman_arabic_converter_25, Can_convert_IXC)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "IXC";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(89, arabicNum);
}

TEST(Test_roman_arabic_converter_26, Can_convert_IXCD)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "IXCD";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(389, arabicNum);
}

TEST(Test_roman_arabic_converter_27, Can_convert_IXCM)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "IXCM";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(889, arabicNum);
}

TEST(Test_roman_arabic_converter_28, Can_convert_VX)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "VX";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_29, Can_convert_LC)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "LC";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_30, Can_convert_DM)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "DM";
    
    //Act
    arabicNum.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}
