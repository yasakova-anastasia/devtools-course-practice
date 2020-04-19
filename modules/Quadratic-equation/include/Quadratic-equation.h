// Copyright 2020 Arisova Anastasiia

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

class QuadraticEquation {
 private:
        double a, b, c;
        double x1, x2;
        int count_roots;
 public:
        QuadraticEquation(double a, double b, double c);
        double GetRoot1();
        double GetRoot2();
        int GetCountRoots();
        void SolveQuadraticEquation();
        void SetNewCoefficients(double a, double b, double c);
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
