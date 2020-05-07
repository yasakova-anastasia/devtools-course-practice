// Copyright 2020 Isaev Ilya

#include "include/rb_tree_application.h"

std::string RBTreeApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return _message;
    }

    return _message;
}

void RBTreeApp::help(const char* appname, const char* message) {
    _message = std::string(message) + "This is a Red-black tree application.\n\n"+
        "Please provide arguments in the following format:\n\n"+
        "  $ " + appname;
}

bool RBTreeApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}