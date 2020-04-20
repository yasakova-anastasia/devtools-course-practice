// Copyright 2020 Sokova Anastasia
#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_

class LengthConverter {
 private:
    double curr;
    int side;
 public:
    LengthConverter() {
        curr = 0;
        side = 0;
    }
    LengthConverter(double currency, int amount) {
        curr = currency;
        side = amount;
    }
    double m_kmeter(const double& curr, int side);
    double m_smeter(const double& curr, int side);
    double m_mile(const double& curr, int side);
    double m_yard(const double& curr, int side);
    double m_ft(const double& curr, int side);
    double m_inch(const double& curr, int side);
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
