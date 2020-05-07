// Copyright 2020 Isaev Ilya

#ifndef MODULES_RB_TREE_INCLUDE_RB_TREE_APPLICATION_H_
#define MODULES_RB_TREE_INCLUDE_RB_TREE_APPLICATION_H_

#include <string>
#include "include/rb_tree.h"

class RBTreeApp {
 public:
    RBTreeApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);

    RBTree _rb;
    std::string _message;
};

#endif  // MODULES_RB_TREE_INCLUDE_RB_TREE_APPLICATION_H_ 