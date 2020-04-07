// Copyright 2020 Brazhnikov Eugene

#include "include/Money_Converter.h";

double MoneyConverter::rubdollar(const double& curr, int  WhichOne) {
    if (curr >= 0 && WhichOne == 0) {  // RUB to EUR
        return curr / 77.73;
    }
    else if (curr >= 0 && WhichOne == 1) {  // EUR to RUB
        return curr * 77.73;
    }
    else {
        return -1;
    }
}

double MoneyConverter::rubeur(const double& curr, int WhichOne) {
    if (curr >= 0 && WhichOne == 0) {
        return curr / 85.73;
    }
    else if (curr >= 0 && WhichOne == 1) {
        return curr * 85.73;
    }
    else {
        return -1;
    }
}

double MoneyConverter::rubJPY(const double& curr, int WhichOne) {
    if (curr >= 0 && WhichOne == 0) {
        return curr / 71.40;
    }
    else if (curr >= 0 && WhichOne == 1) {
        return curr * 71.40;
    }
    else {
        return -1;
    }
}

double MoneyConverter::rubSEK(const double& curr, int WhichOne) {
    if (curr >= 0 && WhichOne == 0) {
        return curr / 78;
    }
    else if (curr >= 0 && WhichOne == 1) {
        return curr * 78;
    }
    else {
        return -1;
    }
}

double MoneyConverter::rubUAH(const double& curr, int WhichOne) {
    if (curr >= 0 && WhichOne == 0) {
        return curr / 2.79;
    }
    else if (curr >= 0 && WhichOne == 1) {
        return curr * 2.79;
    }
    else {
        return -1;
    }
}