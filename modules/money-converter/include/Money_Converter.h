// Copyright 2020 Brazhnikov Eugene

#ifndef MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_
#define MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_

class MoneyConverter {
 public:
     MoneyConverter() {
         curr = 0;
         WhichOne = 0;
     }
     MoneyConverter(double currency, int amount) {
         curr = currency;
         WhichOne = amount;
     }
     double rubdollar(const double& curr, int WhichOne);
     double rubeur(const double& curr, int WhichOne);
     double rubJPY(const double& curr, int WhichOne);
     double rubSEK(const double& curr, int WhichOne);
     double rubUAH(const double& curr, int WhichOne);
 private:
    double curr;
    int WhichOne;
};

#endif  // MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_
