// Copyright 2020 Mazur Daniil
#include <cmath>
#include <vector>
#include <numeric>
#include <utility>

#ifndef MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_H_
#define MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_H_

class Triangle {
 public:
    Triangle();
    Triangle(const std::pair<double, double>& _a,
      const std::pair<double, double>& _b,
      const std::pair<double, double>& _c);
    Triangle(const Triangle& _triangle);

    std::pair<double, double> getTopA() const;
    std::pair<double, double> getTopB() const;
    std::pair<double, double> getTopC() const;

    void setTopA(const std::pair<double, double>& _top);
    void setTopB(const std::pair<double, double>& _top);
    void setTopC(const std::pair<double, double>& _top);

    Triangle& operator= (const Triangle& _triangle);

    bool operator== (const Triangle& _triangle) const;
    bool operator!= (const Triangle& _triangle) const;

    double side(std::pair<double, double> _top1,
      std::pair<double, double> _top2);

    double cornA();
    double cornB();
    double cornC();

    double perimetr();
    double square();

 private:
    std::pair <double, double> a;
    std::pair <double, double> b;
    std::pair <double, double> c;
};

#endif  // MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_H_
