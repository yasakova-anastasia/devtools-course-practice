// Copyright 2020 Kudryashov Nikita

#ifndef MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_CALCULATOR_H_
#define MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_CALCULATOR_H_

#include <string>
#include <vector>
#include "../include/triangle_param.h"

class TriangleParamCalculator {
 private:
    // Return user's data.
    std::vector<std::string> parseData(int argc, const char** argv);

    // Check whether user's top names are valid.
    bool isTopNamesValid(const std::vector<std::string> &data);

    // Check whether user's number types are valid.
    bool isNumberTypeRight(const std::vector<std::string> &data);

    // Check whether user's requests are valid.
    bool isRequestsValid(const std::vector<std::string> &data);

    // Check whether triangle can be created from user's data.
    bool canCreateTriangle(const std::vector<std::string> &data);

    // Return message whether user's data is valid or not.
    std::string isDataValid(const std::vector<std::string> &data);

    // Return the answer to user's request.
    std::string doRequest(Triangle t, std::string req);

    // Return help message.
    std::string help();

 public:
    std::string calculate(int argc, const char** argv);
};

#endif  // MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_CALCULATOR_H_
