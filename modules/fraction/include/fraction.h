// Copyright 2020 Baldin Alexey

#ifndef MODULES_FRACTION_INCLUDE_FRACTION_H_
#define MODULES_FRACTION_INCLUDE_FRACTION_H_

class Fraction {
 private:
    int nominator;
    int denominator;

 public:
    explicit Fraction(int nom = 1, int den = 1);
    Fraction(const Fraction& f);

    int getNominator() const;
    int getDenominator() const;

    void setNominator(int nom);
    void setDenominator(int den);

    bool operator ==(const Fraction& f) const;
    bool operator !=(const Fraction& f) const;

    void fractionReduction();

    Fraction operator +(const Fraction& f) const;
    Fraction operator -(const Fraction& f) const;
    Fraction operator *(const Fraction& f) const;
    Fraction operator /(const Fraction& f) const;

    Fraction operator +(const int& n) const;
    Fraction operator -(const int& n) const;
    Fraction operator *(const int& n) const;
    Fraction operator /(const int& n) const;

    Fraction& operator=(const Fraction& f);

    double fractionToDouble();
};

int nod(int a, int b);

Fraction operator +(const int& n, const Fraction& f);
Fraction operator -(const int& n, const Fraction& f);
Fraction operator *(const int& n, const Fraction& f);
Fraction operator /(const int& n, const Fraction& f);

#endif  // MODULES_FRACTION_INCLUDE_FRACTION_H_
