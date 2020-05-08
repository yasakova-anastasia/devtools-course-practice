// Copyright 2020 Isaev Ilya

#include <cstring>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "include/rb_tree_application.h"

std::string RBTreeApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return _sstream.str();
    }
    try {
        int offset;
        for (int i = 1; i < argc;) {
            offset = parseOperation(argv+i);
            i += offset;
        }
        return _sstream.str();
    } catch(std::exception& exc) {
        return exc.what();
    }
}

std::string RBTreeApp::help(const char* appname, const char* message) {
    return std::string(message) + "This is a Red-black tree application.\n\n"+
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
        _sstream << help(argv[0]);
        return false;
    }
    return true;
}

int RBTreeApp::parseToValue(const char* strval) {
    auto n = static_cast<int>(std::strlen(strval));

    if ((strval[0] != '-' && !std::isdigit(strval[0])) || (strval[0] == '-' && n == 1))
        throw std::invalid_argument("Invalid value: " + std::string(strval));

    for (int i = 1; i < n; i++) {
        if (!std::isdigit(strval[i]))
            throw std::invalid_argument("Invalid value: " + std::string(strval));
    }
    return std::atoi(strval);
}

int RBTreeApp::parseOperation(const char** ops) {
    if (std::strcmp(ops[0], "insert") == 0) {
        _rb.insert(new Node{parseToValue(ops[1])});

        return 2;
    }
    if (std::strcmp(ops[0], "find") == 0) {
        auto value = parseToValue(ops[1]);
        auto found = _rb.find(value);
        if (found->data) {
            _sstream << "(" << value << " is found) ";  
        } else {
            _sstream << "(" << value << " is not found) ";
        }
        return 2;
    }
    if (std::strcmp(ops[0], "remove") == 0) {
        _rb.remove(parseToValue(ops[1]));

        return 2;
    }
    if (std::strcmp(ops[0], "getRoot") == 0) {
        auto root = _rb.getRoot();

        _sstream << "(Root value: " << root->data << ")";

        return 1;
    }
    throw std::invalid_argument("Bad arguments!");
    return 0;
}