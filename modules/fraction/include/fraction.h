// Copyright 2020 Baldin Alexey

#ifndef MODULES_FRACTION_INCLUDE_FRACTION_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_

class Fraction {
private:
    double nominator;
    double denominator;
public:
    Fraction(double nom = 1, double den = 1);
    double getNominator();
    double getDenominator();
};

#endif // MODULES_FRACTION_INCLUDE_FRACTION_H_