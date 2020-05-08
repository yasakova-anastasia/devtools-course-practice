// Copyright 2020 Isaev Ilya

#include <stdexcept>
#include <iostream>
#include "include/rb_tree_application.h"

std::string RBTreeApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return _message;
    }
    try {
        for (int i = 1; i < argc; ++i) {
            parseOperation(argv+i);
        }
    } catch(std::exception& exc) {
        return exc.what();
    }

    return _message;
}

void RBTreeApp::help(const char* appname, const char* message) {
    _message = std::string(message) + "This is a Red-black tree application.\n\n"+
        "Please provide arguments in the following format:\n\n"+
        "  $ " + appname + "<actions> \n\n" +
        "Where <actions> are: \n\n" + 
        "getRoot - get root element from tree\n" + 
        "find <data> - find element by data\n" + 
        "insert <node> - insert node into tree\n" + 
        "remove <data> - remove element from tree\n ";
}

bool RBTreeApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

int RBTreeApp::parseOperation(const char** ops) {
    throw std::invalid_argument("Bad arguments!");
    return 0;
}