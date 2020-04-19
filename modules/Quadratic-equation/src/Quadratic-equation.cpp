// Copyright 2020 Arisova Anastasiia

#include "include/Quadratic-equation.h"

#include <math.h>

    QuadraticEquation::QuadraticEquation(double aa, double bb, double cc) {
        if (aa == 0.0) {
            throw static_cast<std::string>(
                "The coefficient for x^2 cannot be zero!");
        } else {
            a = aa;
            b = bb;
            c = cc;
        }
    }

    double QuadraticEquation::GetRoot1() {
       return x1;
    }

    double QuadraticEquation::GetRoot2() {
       return x2;
    }

    void QuadraticEquation::SolveQuadraticEquation() {
        double diskriminant = b * b - 4.0 * a * c;

        if (diskriminant == 0.0) {
            x1 = -b / (2.0 * a);
            x2 = x1;
        }
        if (diskriminant > 0.0) {
            x1 = (-b + sqrt(diskriminant)) / (2.0 * a);
            x2 = (-b - sqrt(diskriminant)) / (2.0 * a);
        }
    }
