// Copyright 2020 Devlikamov Vladislav

#include "include/numerical_integration.h"
#include "include/numerical_integration_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <cmath>

class func1 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return x * x;
     }
};

class func2 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return sin(x);
     }
};

class func3 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return x;
     }
};

NumericalIntegrationApp::NumericalIntegrationApp() : message_("") {}

void NumericalIntegrationApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a numerical integration application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <left_bound> <right_bound> " +
          "<number_of_iteration> <number_of_function>" +
          "<number_of_algorithm>\n\n" +

          "Where <left_bound> and <right_bound> arguments" +
          "are double-precision numbers,\n"+
          "<number_of_iteration> is integer and <number_of_iteration>" +
          ">= 1 and <number_of_iteration> <= 100000, \n" +
          "<number_of_function> is integer and takes value {1, 2, 3}\n" +
          "where 1.x^2, 2.sin(x), 3.x\n" +
          "<number_of_algorithm> is integer and takes value"+
          "{1, 2, 3, 4, 5, 6}\n" +
          "where 1.Left_rectangle_method, 2.Right_rectangle_method, " +
          "3.Middle_rectangle_method, " +
          "4.Trapezoid_method, 5.Simpsons_method, 6.Gauss_method\n";
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int parseInt(const char* arg) {
    char* end;
    int value = static_cast<int>(strtol(arg, &end, 10));

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

bool NumericalIntegrationApp::validateNumberOfArguments(int argc,
                                                        const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

bool NumericalIntegrationApp::validateArguments(int argc,
                                                const char**argv) {
    Arguments args;

    args.N = parseInt(argv[3]);
    args.num_function = parseInt(argv[4]);
    args.method = parseInt(argv[5]);
    
    if (args.N < 1 || args.N > 100000) {
        help(argv[0], "Incorrect <number_of_iteration>\n\n");
        return false;
    } else if (args.num_function < 1 || args.num_function > 3) {
        help(argv[0], "Incorrect <number_of_function>\n\n");
        return false;
    } else if (args.method < 1 || args.method > 6) {
        help(argv[0], "Incorrect <number_of_algorithm>\n\n");
        return false;
    }
    return true;
}

std::string NumericalIntegrationApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a = parseDouble(argv[1]);
        args.b = parseDouble(argv[2]);
        args.N = parseInt(argv[3]);
        args.num_function = parseInt(argv[4]);
        args.method = parseInt(argv[5]);
    }
    catch(std::string& str) {
        return str;
    }
    if (!validateArguments(argc, argv)) {
        return message_;
    }
    try {
        if (args.num_function == 1) {
            NumericalIntegration obj(args.a, args.b);
            func1 f;
            printf("%f\n", obj.method[args.method](&f, args.N));
        } else if (args.num_function == 2) {
            NumericalIntegration obj(args.a, args.b);
            func2 f;
            printf("%f\n", obj.method[args.method](&f, args.N));
        } else {
            NumericalIntegration obj(args.a, args.b);
            func3 f;
            printf("%f\n", obj.method[args.method](&f, args.N));
        }
    }
     catch(std::string& str) {
        return str;
    }

    message_ = "";

    return message_;
}
