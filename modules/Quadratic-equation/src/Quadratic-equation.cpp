// Copyright 2020 Arisova Anastasiia

#include "include/Quadratic-equation.h"

#include <math.h>
#include <string>

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
        if (count_roots != 0) {
            return x1;
        } else {
            throw static_cast<std::string>(
                "This equation cannot have real root!");
        }
    }

    double QuadraticEquation::GetRoot2() {
        if (count_roots != 0) {
            return x2;
        } else {
            throw static_cast<std::string>(
                "This equation cannot have real root!");
        }
    }

    void QuadraticEquation::SolveQuadraticEquation() {
        double diskriminant = b * b - 4.0 * a * c;
        if (diskriminant < 0.0) {
            count_roots = 0;
        }

        if (diskriminant == 0.0) {
            count_roots = 1;
            x1 = -b / (2.0 * a);
            x2 = x1;
        }
        if (diskriminant > 0.0) {
            count_roots = 2;
            x1 = (-b + sqrt(diskriminant)) / (2.0 * a);
            x2 = (-b - sqrt(diskriminant)) / (2.0 * a);
        }
    }

    int QuadraticEquation::GetCountRoots() {
       return count_roots;
    }

    void QuadraticEquation::SetNewCoefficients(double aa, 
        double bb, double cc) {
        if (aa == 0.0) {
            throw static_cast<std::string>(
                "The coefficient for x^2 cannot be zero!");
        } else {
            a = aa;
            b = bb;
            c = cc;
        }
    }
