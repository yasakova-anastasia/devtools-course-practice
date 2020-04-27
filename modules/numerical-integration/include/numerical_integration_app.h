// Copyright 2020 Devlikamov Vladislav

#ifndef MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_
#define MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_

#include <string>

class NumericalIntegrationApp {
 public:
    NumericalIntegrationApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double a;
        double b;
        int N;
        int num_function;
        int method;
    } Arguments;
};

#endif  // MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_APP_H_
