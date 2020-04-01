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
