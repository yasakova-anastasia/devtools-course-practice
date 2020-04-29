// Copyright 2020 Baldin Alexey

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/vector3D_calculator.h"

int main(int argc, const char** argv) {
    Vector3DCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
