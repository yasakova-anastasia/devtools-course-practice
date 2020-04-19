// Copyright 2020 Arisova Anastasiia

#include "include/Quadratic-equation.h"
#include <math.h>

    QuadraticEquation::QuadraticEquation(double aa, double bb, double cc) {
        if (a == 0.0) {
            throw "The coefficient for x^2 cannot be zero!";
        } else {
            a = aa;
            b = bb;
            c = cc;
        }
    }
    
    double QuadraticEquation::GetRoot1 () {
       return x1;
    }

    double QuadraticEquation::GetRoot2 () {
       return x2;
    }
