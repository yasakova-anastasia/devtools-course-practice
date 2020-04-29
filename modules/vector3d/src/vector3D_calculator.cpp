// Copyright 2020 Baldin Alexey

#include "include/vector3D.h"
#include "include/vector3D_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>

Vector3DCalculator::Vector3DCalculator() : message_("") {}


void Vector3DCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a 3d vector calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <v1_x> <v1_y> <v1_z> " +
        "<v2_x> <v2_y> <v2_z> <operation>\n\n" +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', 'n' or 'N' (normalization), " +
        "'s' or 'S' (Scalar product), 'v' or 'V' (Vector product). \n ";
}

bool Vector3DCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 8) {
        help(argv[0], "Should be 7 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    }
    else if (strcmp(arg, "-") == 0) {
        op = '-';
    }
    else if (strcmp(arg, "n") == 0 || strcmp(arg, "N") == 0) {
        op = 'n';
    }
    else if (strcmp(arg, "s") == 0 || strcmp(arg, "S") == 0) {
        op = 's';
    }
    else if (strcmp(arg, "v") == 0 || strcmp(arg, "V") == 0) {
        op = 'v';
    }
    else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string Vector3DCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.v1_x = parseDouble(argv[1]);
        args.v1_y = parseDouble(argv[2]);
        args.v1_z = parseDouble(argv[3]);
        args.v2_x = parseDouble(argv[4]);
        args.v2_y = parseDouble(argv[5]);
        args.v2_z = parseDouble(argv[6]);
        args.operation = parseOperation(argv[7]);
    }
    catch (std::string& str) {
        return str;
    }

    Vector3D v1;
    Vector3D v2;
    Vector3D res;

    v1.setX(args.v1_x);
    v1.setY(args.v1_y);
    v1.setZ(args.v1_z);
    v2.setX(args.v2_x);
    v2.setY(args.v2_y);
    v2.setZ(args.v2_z);
    

    std::ostringstream stream;
    switch (args.operation) {
     case '+':
        res = v1 + v2;
        stream << "X = " << res.getX() << " "
               << "Y = " << res.getY() << " "
               << "Z = " << res.getZ();
        break;
     case '-':
        res = v1 - v2;
        stream << "X = " << res.getX() << " "
               << "Y = " << res.getY() << " "
               << "Z = " << res.getZ();
        break;
    }

    message_ = stream.str();
    return message_;
}
