// Copyright 2020 Arisova Anastasiia

#include "include/Quadratic-equation.h"
#include <vector>
#include <string>

    QuadraticEquation::QuadraticEquation(double aa, double bb, double cc){
        if (a == 0.0)
            throw "The coefficient for x^2 cannot be zero!";
        else {
            a = aa;
            b = bb; 
            c = cc;
        }
    }
    