// Copyright 2020 Sokova Anastasia

#include "include/length_converter.h"

double LengthConverter::m_kmeter(const double& curr, bool side) {
    if (curr >= 0 && side == false) {  // meter to santimeter
        return curr / 1000;
    } else if (curr >= 0 && side == true) {  // santimeter to meter
        return curr * 1000;
    } else {
        return -1;
    }
}

double LengthConverter::m_smeter(const double& curr, bool side) {
    if (curr >= 0 && side == false) {
        return curr * 100;
    } else if (curr >= 0 && side == true) {
        return curr / 100;
    } else {
        return -1;
    }
}

double LengthConverter::m_mile(const double& curr, bool side) {
    if (curr >= 0 && side == false) {
        return curr * 0.000621371;
    } else if (curr >= 0 && side == true) {
        return curr / 0.000621371;
	} else {
        return -1;
    }
}

double LengthConverter::m_yard(const double& curr, bool side) {
    if (curr >= 0 && side == false) {
        return curr * 1.09361;
    } else if (curr >= 0 && side == true) {
        return curr / 1.09361;
    } else {
        return -1;
    }
}

double LengthConverter::m_ft(const double& curr, bool side) {
    if (curr >= 0 && side == false) {
        return curr * 3.28084;
    } else if (curr >= 0 && side == true) {
        return curr / 3.28084;
    } else {
        return -1;
    }
}

double LengthConverter::m_inch(const double& curr, bool side) {
    if (curr >= 0 && side == false) {
        return curr * 39.3701;
    } else if (curr >= 0 && side == true) {
        return curr / 39.3701;
    } else {
        return -1;
    }
}
