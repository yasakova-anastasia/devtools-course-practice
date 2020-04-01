//Copyright 2020 Vedrukov Pavel

#include <string>
#include <regex>
#include "include/roman-arabic-converter.h"

int romanToArabic(std::string romanNum) {
    int arabicNum = 0;
    
	//Search not roman
    std::regex regular1("[^IXLCDM]");
	if (std::regex_match(romanNum.c_str(), regular1))
	{
		return -1;
	}
	
	//Search incorrect number
	std::regex regular2("VX|LC|DM|IIII|VV|XXXX|LL|CCCC|DD|MMMM");
	if (std::regex_match(romanNum.c_str(), regular2))
	{
		return -2;
	}
	
	return arabicNum;
}

std::string arabicToRoman(int arabicNum) {
    std::string romanNum = "I";

    return romanNum;	
}
