// Copyright 2020 Yasakova Anastasia

#include "include/queue_application.h"
#include <iostream>

int main(int argc, const char** argv) {
    QueueApp app;
    std::string output = app(argc, argv);
    std::cout << output.c_str();
    return 0;
}