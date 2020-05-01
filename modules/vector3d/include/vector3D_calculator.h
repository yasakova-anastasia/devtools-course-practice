// Copyright 2020 Baldin Alexey

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::stod;
using std::invalid_argument;
using std::ostringstream;

class Vector3DCalculator {
 public:
    Vector3DCalculator();
    virtual string calculate(const string* argv) = 0;

 protected:
    string message_;
    char operation;
 
};

class Vector3DCalculatorForOneVector : public Vector3DCalculator {
 public:
    Vector3DCalculatorForOneVector() : Vector3DCalculator() {};
    string calculate(const string* argv);

 private:
    vector<double> v;

};

class Vector3DCalculatorForTwoVectors : public Vector3DCalculator {
 public:
    Vector3DCalculatorForTwoVectors() : Vector3DCalculator() {};
    string calculate(const string* argv);

 private:
    vector<double> v1;
    vector<double> v2;

};

class Vector3DApplication {
 public:
    Vector3DApplication();
    string operator()(int argc, const char** argv);

 private:
    void help(const string appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const string* argv);

    string message_;

};

#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_
