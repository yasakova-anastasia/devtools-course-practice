//Copyright 2020 Vedrukov Pavel

#include <string>
#include "include/roman-arabic-converter.h"

int RomanArabicConverter::romanToArabic(std::string romanNum) {
    int arabicNum = 0;
    
	//Search not roman
    for (unsigned int i = 0; i < romanNum.size(); i++) {
		if (romanNum[i] != 'I' && romanNum[i] != 'V' && romanNum[i] != 'X' &&
		    romanNum[i] != 'L' && romanNum[i] != 'C' && romanNum[i] != 'D' &&
			romanNum[i] != 'M') {
			throw "It is not roman number";
			}
	}
	
	//Search incorrect number
	for (unsigned int i = 0; i < romanNum.size(); i++) {
		if (romanNum[i] == 'I') {
			if (i < romanNum.size() - 3 && romanNum[i + 1] == 'I' && 
			    romanNum[i + 2] == 'I' && romanNum[i + 3] == 'I') {
				throw "Incorrect input of the roman number";			
			}
			if (i < romanNum.size() - 2) {
				if ((romanNum[i + 1] == 'X' && romanNum[i + 2] == 'L') ||
				    (romanNum[i + 1] == 'X' && romanNum[i + 2] == 'C')) {
					throw "Incorrect input of the roman number";
				}
			}
			if (i < romanNum.size() - 1) {
				if (romanNum[i + 1] == 'L' || romanNum[i + 1] == 'C' ||
				    romanNum[i + 1] == 'D' || romanNum[i + 1] == 'M') {
					throw "Incorrect input of the roman number";
				}
			}
		}
		if (romanNum[i] == 'V') {
			if (i < romanNum.size() - 1 && (romanNum[i + 1] == 'V' ||
			    romanNum[i + 1] == 'X' || romanNum[i + 1] == 'L' ||
				romanNum[i + 1] == 'C' || romanNum[i + 1] == 'D' ||
				romanNum[i + 1] == 'M')) {
				throw "Incorrect input of the roman number";			
			}
		}
		if (romanNum[i] == 'X') {
			if (i < romanNum.size() - 3 && romanNum[i + 1] == 'X' && 
			    romanNum[i + 2] == 'X' && romanNum[i + 3] == 'X') {
				throw "Incorrect input of the roman number";			
			}
			if (i < romanNum.size() - 2) {
				if ((romanNum[i + 1] == 'C' && romanNum[i + 2] == 'D') ||
				    (romanNum[i + 1] == 'C' && romanNum[i + 2] == 'M')) {
					throw "Incorrect input of the roman number";
				}
			}
			if (i < romanNum.size() - 1) {
				if (romanNum[i + 1] == 'D' || romanNum[i + 1] == 'M') {
					throw "Incorrect input of the roman number";
				}
			}
		}
		if (romanNum[i] == 'L') {
			if (i < romanNum.size() - 1 && (romanNum[i + 1] == 'L' ||
			    romanNum[i + 1] == 'C' || romanNum[i + 1] == 'D' ||
				romanNum[i + 1] == 'M')) {
				throw "Incorrect input of the roman number";			
			}
		}
		if (romanNum[i] == 'C') {
			if (i < romanNum.size() - 3 && romanNum[i + 1] == 'C' && 
			    romanNum[i + 2] == 'C' && romanNum[i + 3] == 'C') {
				throw "Incorrect input of the roman number";			
			}
		}
		if (romanNum[i] == 'D') {
			if (i < romanNum.size() - 1 && (romanNum[i + 1] == 'D' ||
				romanNum[i + 1] == 'M')) {
				throw "Incorrect input of the roman number";			
			}
		}
		if (romanNum[i] == 'M') {
			if (i < romanNum.size() - 3 && romanNum[i + 1] == 'M' && 
			    romanNum[i + 2] == 'M' && romanNum[i + 3] == 'M') {
				throw "Incorrect input of the roman number";			
			}
		}
	}
	
	//Convert roman to arabic
	for (unsigned int i = 0; i < romanNum.size(); i++) {
		switch (romanNum[i]) {
			case 'M':
			    arabicNum += 1000;
				break;
			case 'D':
 			    arabicNum += 500;
				break;
			case 'C':
                if (romanNum[i + 1] == 'D' && i != romanNum.size() - 1) {
			        i++;
				    arabicNum += 400;
					break;
			    }
				if (romanNum[i + 1] == 'M' && i != romanNum.size() - 1) {
			        i++;
				    arabicNum += 900;
					break;
			    }
				arabicNum += 100;
				break;	
            case 'L':
                arabicNum += 50;
				break;
            case 'X':
                if (romanNum[i + 1] == 'L' && i != romanNum.size() - 1) {
			        i++;
				    arabicNum += 40;
					break;
			    }
				if (romanNum[i + 1] == 'C' && i != romanNum.size() - 1) {
			        i++;
				    arabicNum += 90;
					break;
			    }
				arabicNum += 10;
				break;	
            case 'V':
                arabicNum += 5;
				break;
            case 'I':
                if (romanNum[i + 1] == 'V' && i != romanNum.size() - 1) {
			        i++;
				    arabicNum += 4;
					break;
			    }
                if (romanNum[i + 1] == 'X' && i != romanNum.size() - 1) {
			        i++;
				    arabicNum += 9;
					break;
				}
				arabicNum += 1;
				break;
            default:
                break;			
		}
	}
	
	return arabicNum;
}

std::string RomanArabicConverter::arabicToRoman(int arabicNum) {
    std::string romanNum = "";
    
	if (arabicNum < 1 || arabicNum > 3999) {
		throw "OutOfRange";
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
