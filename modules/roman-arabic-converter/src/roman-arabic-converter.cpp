//Copyright 2020 Vedrukov Pavel

#include <string>
#include <regex>
#include "include/roman-arabic-converter.h"

int RomanArabicConverter::romanToArabic(std::string romanNum) {
    int arabicNum = 0;
    
	//Search not roman
    std::regex regular1("[.]*[^IVXLCDM]*");
	if (std::regex_match(romanNum.c_str(), regular1)) {
		return -1;
	}
	
	//Search incorrect number
	std::regex regular2("[.]*IIII|VV|XXXX|LL|CCCC|DD|MMMM|IL|IC|ID|IM|VX|VL|VC|VD|VM|XD|XM|LC|LD|LM|DM*");
	if (std::regex_match(romanNum.c_str(), regular2)) {
		return -2;
	}
	
	return arabicNum;
}

std::string RomanArabicConverter::arabicToRoman(int arabicNum) {
    std::string romanNum = "I";
    
	if (arabicNum < 1 || arabicNum > 3999) {
		return "InputNumOutOfRange";
	}
	
    return romanNum;	
}
