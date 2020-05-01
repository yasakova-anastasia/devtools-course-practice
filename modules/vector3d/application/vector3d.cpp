// Copyright 2020 Baldin Alexey

#include <string>
#include <iostream>

#include "include/vector3D_calculator.h"

using std::cout;

int main(int argc, const char** argv) {
    Vector3DApplication app;
    string output = app(argc, argv);
    cout << output.c_str();
    return 0;
}
