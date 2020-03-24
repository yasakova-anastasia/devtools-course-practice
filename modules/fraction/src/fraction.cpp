// Copyright 2020 Baldin Alexey

#include "include/fraction.h"
#include <string>

Fraction::Fraction(int nom, int den) {
    nominator = nom;

    if (den == 0.0) {
        denominator = 1.0;
        throw std::string("Denominator can`t be zero. Use denominator = 1.0");
    } else {
        denominator = den;
    }
}

int Fraction::getNominator() const {
    return nominator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNominator(int nom) {
    nominator = nom;
}

void Fraction::setDenominator(int den) {
    if (den == 0.0) {
        denominator = 1.0;
        throw std::string("Denominator can`t be zero. Use denominator = 1.0");
    } else {
        denominator = den;
    }
}

bool Fraction::operator==(const Fraction & f) const {
    return this->getNominator() == f.getNominator() &&
           this->getDenominator() == f.getDenominator();
}

bool Fraction::operator!=(const Fraction & f) const {
    return this->getNominator() != f.getNominator() ||
           this->getDenominator() != f.getDenominator();
}

int nod(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    while (a & b) {
        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if (a == 0) {
        return b;
    } else {
        return a;
    }
}
