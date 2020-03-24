// Copyright 2020 Baldin Alexey

#include "include/fraction.h"
#include <string>
#include <iostream>

Fraction::Fraction(int nom, int den) {
    if (den == 0) {
        denominator = 1;
        throw std::string("Denominator can`t be zero. Use denominator = 1");
    } else if (den < 0) {
        nominator = -nom;
        denominator = -den;
    } else {
        nominator = nom;
        denominator = den;
    }
}

Fraction::Fraction(const Fraction & f) {
    this->nominator = f.getNominator();
    this->denominator = f.getDenominator();
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
    if (den == 0) {
        denominator = 1;
        throw std::string("Denominator can`t be zero. Use denominator = 1");
    } else if (den < 0) {
        nominator = -nominator;
        denominator = -den;
    } else {
        denominator = den;
    }
}

bool Fraction::operator==(const Fraction & f) const {
    int n1 = this->getNominator();
    int d1 = this->getDenominator();
    int n2 = f.getNominator();
    int d2 = f.getDenominator();

    int nod1 = nod(n1, d1);
    int nod2 = nod(n2, d2);

    if (nod1 != 1) {
        n1 = n1 / nod1;
    }

    if (nod2 != 1) {
        n2 = n2 / nod2;
    }

    return n1 == n2;
}

bool Fraction::operator!=(const Fraction & f) const {
    int n1 = this->getNominator();
    int d1 = this->getDenominator();
    int n2 = f.getNominator();
    int d2 = f.getDenominator();
    int nod1 = nod(n1, d1);
    int nod2 = nod(n2, d2);

    if (nod1 != 1) {
        n1 = n1 / nod1;
    }
    if (nod2 != 1) {
        n2 = n2 / nod2;
    }

    return n1 != n2;
}

void Fraction::fractionReduction() {
    int nodND = nod(nominator, denominator);

    if (nodND != 1) {
        nominator = nominator / nodND;
        denominator = denominator / nodND;
    }
}

Fraction Fraction::operator+(const Fraction & f) const {
    int nom = this->getNominator() * f.getDenominator() +
              this->getDenominator() * f.getNominator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction sum(nom, den);
    sum.fractionReduction();

    return sum;
}

Fraction Fraction::operator-(const Fraction & f) const {
    int nom = this->getNominator() * f.getDenominator() -
        this->getDenominator() * f.getNominator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction dif(nom, den);
    dif.fractionReduction();

    return dif;
}

Fraction Fraction::operator*(const Fraction & f) const {
    int nom = this->getNominator() * f.getNominator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction mult(nom, den);
    mult.fractionReduction();

    return mult;
}

Fraction Fraction::operator/(const Fraction & f) const {
    int nom = this->getNominator() * f.getDenominator();
    int den = this->getDenominator() * f.getNominator();

    Fraction div(nom, den);
    div.fractionReduction();

    return div;
}

Fraction& Fraction::operator=(const Fraction & f) {
    this->nominator = f.getNominator();
    this->denominator = f.getDenominator();

    return *this;
}

int nod(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    while (a && b) {
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
