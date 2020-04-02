// Copyright 2020 Vedrukov Pavel

#include <gtest/gtest.h>

#include <string>
#include "include/roman-arabic-converter.h"

TEST(Test_roman_arabic_converter_1, Can_convert_zero)
{
    //Arrange
    int arabicNum = 0;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("InputNumOutOfRange", romanNum);
}

TEST(Test_roman_arabic_converter_2, Can_convert_4000)
{
    //Arrange
    int arabicNum = 4000;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("InputNumOutOfRange", romanNum);
}

TEST(Test_roman_arabic_converter_3, Can_convert_1)
{
    //Arrange
    int arabicNum = 1;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("I", romanNum);
}

TEST(Test_roman_arabic_converter_4, Can_convert_2)
{
    //Arrange
    int arabicNum = 2;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("II", romanNum);
}

TEST(Test_roman_arabic_converter_5, Can_convert_3)
{
    //Arrange
    int arabicNum = 3;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("III", romanNum);
}

TEST(Test_roman_arabic_converter_6, Can_convert_4)
{
    //Arrange
    int arabicNum = 4;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("IV", romanNum);
}

TEST(Test_roman_arabic_converter_7, Can_convert_9)
{
    //Arrange
    int arabicNum = 9;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("IX", romanNum);
}

TEST(Test_roman_arabic_converter_8, Can_convert_40)
{
    //Arrange
    int arabicNum = 40;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("XL", romanNum);
}

TEST(Test_roman_arabic_converter_9, Can_convert_41)
{
    //Arrange
    int arabicNum = 41;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("XLI", romanNum);
}

TEST(Test_roman_arabic_converter_10, Can_convert_97)
{
    //Arrange
    int arabicNum = 97;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("XCVII", romanNum);
}

TEST(Test_roman_arabic_converter_11, Can_convert_471)
{
    //Arrange
    int arabicNum = 471;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("CDLXXI", romanNum);
}

TEST(Test_roman_arabic_converter_12, Can_convert_2879)
{
    //Arrange
    int arabicNum = 2879;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("MMDCCCLXXIX", romanNum);
}

TEST(Test_roman_arabic_converter_13, Can_convert_3999)
{
    //Arrange
    int arabicNum = 3999;
    std::string romanNum;
    RomanArabicConverter converter;
	
    //Act
    romanNum = converter.arabicToRoman(arabicNum);
    
    //Assert
	ASSERT_EQ("MMMCMXCIX", romanNum);
}

TEST(Test_roman_arabic_converter_14, Can_convert_not_roman)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "Error";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-1, arabicNum);
}

TEST(Test_roman_arabic_converter_15, Can_convert_IIII)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "IIII";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_16, Can_convert_VV)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "VV";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_17, Can_convert_XXXX)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "XXXX";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_18, Can_convert_LL)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "LL";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_19, Can_convert_CCCC)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "CCCC";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_20, Can_convert_DD)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "DD";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_21, Can_convert_MMMM)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "MMMM";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_22, Can_convert_IL)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "IL";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_23, Can_convert_IC)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "IC";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_24, Can_convert_ID)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "ID";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_25, Can_convert_IM)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "IM";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_26, Can_convert_VX)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "VX";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_27, Can_convert_VL)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "VL";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_28, Can_convert_VC)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "VC";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_29, Can_convert_VD)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "VD";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_30, Can_convert_VM)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "VM";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_31, Can_convert_XD)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "XD";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_32, Can_convert_XM)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "XM";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_33, Can_convert_LC)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "LC";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_34, Can_convert_LD)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "LD";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_35, Can_convert_LM)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "LM";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_36, Can_convert_DM)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "DM";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(-2, arabicNum);
}

TEST(Test_roman_arabic_converter_37, Can_convert_IV)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "IV";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(4, arabicNum);
}

TEST(Test_roman_arabic_converter_38, Can_convert_IX)
{
    //Arrange
    short int arabicNum;
    std::string romanNum = "IX";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(9, arabicNum);
}

TEST(Test_roman_arabic_converter_39, Can_convert_XL)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "XL";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(40, arabicNum);
}

TEST(Test_roman_arabic_converter_40, Can_convert_IXC)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "IXC";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(89, arabicNum);
}

TEST(Test_roman_arabic_converter_41, Can_convert_IXCD)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "IXCD";
	RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(389, arabicNum);
}

TEST(Test_roman_arabic_converter_42, Can_convert_IXCM)
{
    //Arrange
    int arabicNum;
    std::string romanNum = "IXCM";
    RomanArabicConverter converter;
    
    //Act
    arabicNum = converter.romanToArabic(romanNum);
    
    //Assert
	ASSERT_EQ(889, arabicNum);
}
