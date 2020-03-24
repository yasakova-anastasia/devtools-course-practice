// Copyright 2020 Baldin Alexey

#ifndef MODULES_FRACTION_INCLUDE_FRACTION_H_
#define MODULES_FRACTION_INCLUDE_FRACTION_H_

class Fraction {
 private:
    int nominator;
    int denominator;

 public:
    explicit Fraction(int nom = 1, int den = 1);
    
    int getNominator() const;
    int getDenominator() const;
    
    void setNominator(int nom);
    void setDenominator(int den);

    bool operator ==(const Fraction& f) const;
    bool operator !=(const Fraction& f) const;
};

int nod(int a, int b);
#endif  // MODULES_FRACTION_INCLUDE_FRACTION_H_
