// Copyright 2020 Devlikamov Vladislav

#ifndef MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_H_
#define MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_H_

#include <map>
#include <functional>

class FunctionsForIntegration {
 public:
     virtual double f(double x) = 0;
};

class NumericalIntegration {
 private:
    double a, b;

 public:
    std::map<int, std::function<double(FunctionsForIntegration*,
                                      unsigned int)> > method;
    NumericalIntegration(double _a, double _b);
    NumericalIntegration(const NumericalIntegration& obj) : a(obj.a),
    b(obj.b) {}
    NumericalIntegration& operator=(const NumericalIntegration& obj);

    bool operator == (const NumericalIntegration& obj) const;
    void Set_integration_borders(double _a, double _b);
    double Get_left_border() const;
    double Get_right_border() const;

    double Left_rectangle_method(
        FunctionsForIntegration* func, unsigned int N);
    double Right_rectangle_method(
        FunctionsForIntegration* func, unsigned int N);
    double Middle_rectangle_method(
        FunctionsForIntegration* func, unsigned int N);
    double Trapezoid_method(
        FunctionsForIntegration* func, unsigned int N);
    double Simpsons_method(
        FunctionsForIntegration* func, unsigned int N);
    double Gauss_method(
        FunctionsForIntegration* func, unsigned int N);
};

#endif  // MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_H_
