// Copyright 2020 Baldin Alexey

#include "include/fraction.h"

Fraction::Fraction(double nom, double den) {
    nominator = nom;
    denominator = den;
}

double Fraction::getNominator()
{
    return nominator;
}

double Fraction::getDenominator()
{
    return denominator;
}
