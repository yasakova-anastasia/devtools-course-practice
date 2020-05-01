// Copyright 2020 Baldin Alexey

#include <string>

#include "include/vector3D.h"
#include "include/vector3D_calculator.h"

Vector3DCalculator::Vector3DCalculator() : message_("") {}

Vector3DApplication::Vector3DApplication() : message_("") {}

void Vector3DApplication::help(const string appname, const char * message) {
    message_ =
        std::string(message) +
        "This is a 3d vector calculator application.\n\n" +
        "If you want use normalization, please " +
        "provide arguments in the following format:\n\n" +
        "  $ " + appname + " <v_x> <v_y> <v_z> <operation> \n\n" +
        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of 'n' or 'N', " +
        "'l' or 'L' (Vector length).\n\n" +
        "If you want use another operations, please " +
        "provide arguments in the following format:\n\n" +
        "  $ " + appname + " <v1_x> <v1_y> <v1_z> " +
        "<v2_x> <v2_y> <v2_z> <operation>\n\n" +
        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', " +
        "'s' or 'S' (Scalar product), 'v' or 'V' (Vector product). \n";
}

bool Vector3DApplication::validateNumberOfArguments(int argc,
    const string* argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 8 && argc != 5) {
        help(argv[0], "Should be 4 or 7 arguments.\n\n");
        return false;
    }
    return true;
}

string Vector3DApplication::operator()(int argc, const char ** argv) {
    string *arguments = new string[argc];
    for (int i = 0; i < argc; ++i) {
        arguments[i] = argv[i];
    }

    if (!validateNumberOfArguments(argc, arguments)) {
        return message_;
    }

    Vector3DCalculator* calc;

    if (argc == 5) {
        calc = new Vector3DCalculatorForOneVector();
    }
    else {
        calc = new Vector3DCalculatorForTwoVectors();
    }

    message_ = calc->calculate(arguments);

    delete calc;
    delete[] arguments;

    return message_;
}

char parseOperationForOneVector(char arg) {
    arg = tolower(arg);

    switch (arg) {
    case 'n':
        return arg;
    case 'l':
        return arg;
    default:
        throw std::string("Wrong operation format!");
    }
}

string Vector3DCalculatorForOneVector::calculate(const string* argv) {
    try {
        v.resize(3);
        v[0] = stod(argv[1]);
        v[1] = stod(argv[2]);
        v[2] = stod(argv[3]);
    }
    catch (invalid_argument& arg) {
        return string("Wrong number format!");
    }

    try {
        operation = parseOperationForOneVector(argv[4][0]);
    }
    catch (string& str) {
        return str;
    }
    

    Vector3D resVec(v[0], v[1], v[2]); 
    double resDouble;
    ostringstream stream;

    switch (operation) {
    case 'n':
        try {
            resVec.normalization();
            stream << "X = " << resVec.getX() << " "
                   << "Y = " << resVec.getY() << " "
                   << "Z = " << resVec.getZ();
            break;
        }
        catch (string& str) {
            return str;
        }
    case 'l':
        resDouble = resVec.norm();
        stream << "Vector length = " << resDouble;
        break;
    }
 
    message_ = stream.str();

    return message_;
}

char parseOperationForTwoVectors(char arg) {
    arg = tolower(arg);

    switch (arg) {
    case '+':
        return arg;
    case '-':
        return arg;
    case 's':
        return arg;
    case 'v':
        return arg;
    default:
        throw std::string("Wrong operation format!");
    }
}

string Vector3DCalculatorForTwoVectors::calculate(const string* argv) {
    try {
        v1.resize(3);
        v2.resize(3);
        v1[0] = stod(argv[1]);
        v1[1] = stod(argv[2]);
        v1[2] = stod(argv[3]);
        v2[0] = stod(argv[4]);
        v2[1] = stod(argv[5]);
        v2[2] = stod(argv[6]);
    }
    catch (invalid_argument& arg) {
        return string("Wrong number format!");
    }

    try {
        operation = parseOperationForTwoVectors(argv[7][0]);
    }
    catch (string& str) {
        return str;
    }

    Vector3D vec1(v1[0], v1[1], v1[2]);
    Vector3D vec2(v2[0], v2[1], v2[2]);
    Vector3D resVec;
    double resDouble;
    ostringstream stream;

    switch (operation) {
    case '+':
        resVec = vec1 + vec2;
        stream << "X = " << resVec.getX() << " "
               << "Y = " << resVec.getY() << " "
               << "Z = " << resVec.getZ();
        break;
    case '-':
        resVec = vec1 - vec2;
        stream << "X = " << resVec.getX() << " "
               << "Y = " << resVec.getY() << " "
               << "Z = " << resVec.getZ();
        break;
    case 's':
        resDouble = ScalarProduct(vec1, vec2);
        stream << "Scalar product = " << resDouble;
        break;
    case 'v':
        resVec = VectorProduct(vec1, vec2);
        stream << "X = " << resVec.getX() << " "
               << "Y = " << resVec.getY() << " "
               << "Z = " << resVec.getZ();
        break;
    }

    message_ = stream.str();

    return message_;
}
