// Copyright 2020 Vedrukov Pavel

#include <gtest/gtest.h>

#include <string>
#include "include/roman-arabic-converter.h"

TEST(Test_roman_arabic_converter_1, Can_convert_zero) {
    // Arrange
    int arabicNum = 0;
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.arabicToRoman(arabicNum));
}

TEST(Test_roman_arabic_converter_2, Can_convert_4000) {
    // Arrange
    int arabicNum = 4000;
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.arabicToRoman(arabicNum));
}

TEST(Test_roman_arabic_converter_3, Can_convert_1111) {
    // Arrange
    int arabicNum = 1111;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("MCXI", romanNum);
}

TEST(Test_roman_arabic_converter_4, Can_convert_2222) {
    // Arrange
    int arabicNum = 2222;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("MMCCXXII", romanNum);
}

TEST(Test_roman_arabic_converter_5, Can_convert_3333) {
    // Arrange
    int arabicNum = 3333;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("MMMCCCXXXIII", romanNum);
}

TEST(Test_roman_arabic_converter_6, Can_convert_444) {
    // Arrange
    int arabicNum = 444;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("CDXLIV", romanNum);
}

TEST(Test_roman_arabic_converter_7, Can_convert_555) {
    // Arrange
    int arabicNum = 555;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("DLV", romanNum);
}

TEST(Test_roman_arabic_converter_8, Can_convert_666) {
    // Arrange
    int arabicNum = 666;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("DCLXVI", romanNum);
}

TEST(Test_roman_arabic_converter_9, Can_convert_777) {
    // Arrange
    int arabicNum = 777;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("DCCLXXVII", romanNum);
}

TEST(Test_roman_arabic_converter_10, Can_convert_888) {
    // Arrange
    int arabicNum = 888;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("DCCCLXXXVIII", romanNum);
}

TEST(Test_roman_arabic_converter_11, Can_convert_999) {
    // Arrange
    int arabicNum = 999;
    std::string romanNum;
    RomanArabicConverter converter;

    // Act
    romanNum = converter.arabicToRoman(arabicNum);

    // Assert
    ASSERT_EQ("CMXCIX", romanNum);
}

TEST(Test_roman_arabic_converter_12, Can_convert_not_roman) {
    // Arrange
    std::string romanNum = "Error";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_13, Can_convert_IIII) {
    // Arrange
    std::string romanNum = "IIII";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_14, Can_convert_VV) {
    // Arrange
    std::string romanNum = "VV";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_15, Can_convert_XXXX) {
    // Arrange
    std::string romanNum = "XXXX";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_16, Can_convert_LL) {
    // Arrange
    std::string romanNum = "LL";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_17, Can_convert_CCCC) {
    // Arrange
    std::string romanNum = "CCCC";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_18, Can_convert_DD) {
    // Arrange
    std::string romanNum = "DD";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_19, Can_convert_MMMM) {
    // Arrange
    std::string romanNum = "MMMM";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_20, Can_convert_IL) {
    // Arrange
    std::string romanNum = "IL";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_21, Can_convert_IC) {
    // Arrange
    std::string romanNum = "IC";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_22, Can_convert_ID) {
    // Arrange
    std::string romanNum = "ID";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_23, Can_convert_IM) {
    // Arrange
    std::string romanNum = "IM";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_24, Can_convert_VX) {
    // Arrange
    std::string romanNum = "VX";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_25, Can_convert_VL) {
    // Arrange
    std::string romanNum = "VL";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_26, Can_convert_VC) {
    // Arrange
    std::string romanNum = "VC";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_27, Can_convert_VD) {
    // Arrange
    std::string romanNum = "VD";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_28, Can_convert_VM) {
    // Arrange
    std::string romanNum = "VM";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_29, Can_convert_XD) {
    // Arrange
    std::string romanNum = "XD";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_30, Can_convert_XM) {
    // Arrange
    std::string romanNum = "XM";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_31, Can_convert_LC) {
    // Arrange
    std::string romanNum = "LC";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_32, Can_convert_LD) {
    // Arrange
    std::string romanNum = "LD";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_33, Can_convert_LM) {
    // Arrange
    std::string romanNum = "LM";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_34, Can_convert_DM) {
    // Arrange
    std::string romanNum = "DM";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_35, Can_convert_IXL) {
    // Arrange
    std::string romanNum = "IXL";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_36, Can_convert_XCD) {
    // Arrange
    std::string romanNum = "XCD";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_37, Can_convert_XCM) {
    // Arrange
    std::string romanNum = "XCM";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_38, Can_convert_IXC) {
    // Arrange
    std::string romanNum = "IXC";
    RomanArabicConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.romanToArabic(romanNum));
}

TEST(Test_roman_arabic_converter_39, Can_convert_MDCLXVI) {
    // Arrange
    int arabicNum;
    std::string romanNum = "MDCLXVI";
    RomanArabicConverter converter;

    // Act
    arabicNum = converter.romanToArabic(romanNum);

    // Assert
    ASSERT_EQ(1666, arabicNum);
}

TEST(Test_roman_arabic_converter_40, Can_convert_CDXLIV) {
    // Arrange
    int arabicNum;
    std::string romanNum = "CDXLIV";
    RomanArabicConverter converter;

    // Act
    arabicNum = converter.romanToArabic(romanNum);

    // Assert
    ASSERT_EQ(444, arabicNum);
}

TEST(Test_roman_arabic_converter_41, Can_convert_CMXCIX) {
    // Arrange
    int arabicNum;
    std::string romanNum = "CMXCIX";
    RomanArabicConverter converter;

    // Act
    arabicNum = converter.romanToArabic(romanNum);

    // Assert
    ASSERT_EQ(999, arabicNum);
}
