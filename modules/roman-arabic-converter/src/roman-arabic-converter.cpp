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
    std::string romanNum = "";
    
	if (arabicNum < 1 || arabicNum > 3999) {
		return "InputNumOutOfRange";
	}
	
	int digitArabicNum[4] = {arabicNum / 1000, arabicNum % 1000 / 100, arabicNum % 100 / 10, arabicNum % 10};
	
	switch (digitArabicNum[3]) {
		case 1:
		    romanNum.insert(0, "I");
			break;
	    case 2:
		    romanNum.insert(0, "II");
			break;
		case 3:
		    romanNum.insert(0, "III");
			break;
	    case 4:
		    romanNum.insert(0, "IV");
			break;
	    case 5:
		    romanNum.insert(0, "V");
			break;
		case 6:
		    romanNum.insert(0, "VI");
			break;
	    case 7:
		    romanNum.insert(0, "VII");
			break;
	    case 8:
		    romanNum.insert(0, "VIII");
			break;
		case 9:
		    romanNum.insert(0, "IX");
			break;
        default:
            break;		
	}
	
	switch (digitArabicNum[2]) {
		case 1:
		    romanNum.insert(0, "X");
			break;
	    case 2:
		    romanNum.insert(0, "XX");
			break;
		case 3:
		    romanNum.insert(0, "XXX");
			break;
	    case 4:
		    romanNum.insert(0, "XL");
			break;
	    case 5:
		    romanNum.insert(0, "L");
			break;
		case 6:
		    romanNum.insert(0, "LX");
			break;
	    case 7:
		    romanNum.insert(0, "LXX");
			break;
	    case 8:
		    romanNum.insert(0, "LXXX");
			break;
		case 9:
		    romanNum.insert(0, "XC");
			break;
        default:
            break;		
	}
	
	switch (digitArabicNum[1]) {
		case 1:
		    romanNum.insert(0, "C");
			break;
	    case 2:
		    romanNum.insert(0, "CC");
			break;
		case 3:
		    romanNum.insert(0, "CCC");
			break;
	    case 4:
		    romanNum.insert(0, "CD");
			break;
	    case 5:
		    romanNum.insert(0, "D");
			break;
		case 6:
		    romanNum.insert(0, "DC");
			break;
	    case 7:
		    romanNum.insert(0, "DCC");
			break;
	    case 8:
		    romanNum.insert(0, "DCCC");
			break;
		case 9:
		    romanNum.insert(0, "CM");
			break;
        default:
            break;		
	}
	
	switch (digitArabicNum[0]) {
		case 1:
		    romanNum.insert(0, "M");
			break;
	    case 2:
		    romanNum.insert(0, "MM");
			break;
		case 3:
		    romanNum.insert(0, "MMM");
			break;
        default:
            break;		
	}
	
    return romanNum;	
}
