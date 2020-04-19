// Copyright 2020 Boganov Sergei

#ifndef MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_H_
#define MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_H_

class NumericalIntegration {
public:
   double a, b;
   double (*f)(double x);   

   NumericalIntegration(double _a, double _b, double (*_f)(double x)) : a(_a), b(_b), f(_f) {};
};

#endif  // MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_H_
