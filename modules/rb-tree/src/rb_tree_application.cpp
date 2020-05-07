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