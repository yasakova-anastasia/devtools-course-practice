// Copyright 2020 Baldin Alexey

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_

#include <string>

class Vector3DCalculator {
 public:
    Vector3DCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double v1_x;
        double v1_y;
        double v1_z;
        double v2_x;
        double v2_y;
        double v2_z;
        char operation;
    } Arguments;
};

#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_
