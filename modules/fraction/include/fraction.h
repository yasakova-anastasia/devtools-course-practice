// Copyright 2020 Baldin Alexey

#ifndef MODULES_FRACTION_INCLUDE_FRACTION_H_
#define MODULES_FRACTION_INCLUDE_FRACTION_H_

class Fraction {
 private:
    double nominator;
    double denominator;
 public:
    explicit Fraction(double nom = 1, double den = 1);
    double getNominator();
    double getDenominator();
};

#endif  // MODULES_FRACTION_INCLUDE_FRACTION_H_
