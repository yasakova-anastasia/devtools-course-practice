// Copyright 2020 Isaev Ilya

#ifndef MODULES_RB_TREE_INCLUDE_RB_OPERATION_H_
#define MODULES_RB_TREE_INCLUDE_RB_OPERATION_H_

#include <string>
#include <vector>
#include "include/rb_tree.h"

class RBOperation {
 public:
    RBOperation() = default;
    virtual ~RBOperation() = default;
    static RBOperation* makeOperation(std::string op);
    virtual std::string operator()(RBTree* tree,
        const std::vector<int>& arg) = 0;
    int getArgc() {return argc;}
 protected:
    int isNIL(Node* node);
    int argc;
};

class InsertOperation: public RBOperation{
 public:
    InsertOperation() {this->argc = 2;}
    std::string operator()(RBTree* tree, const std::vector<int>& arg) override;
};

class FindOperation: public RBOperation{
 public:
    FindOperation() {this->argc = 2;}
    std::string operator()(RBTree* tree, const std::vector<int>& arg) override;
};

class RemoveOperation: public RBOperation{
 public:
    RemoveOperation() {this->argc = 2;}
    std::string operator()(RBTree* tree, const std::vector<int>& arg) override;
};

class GetRootOperation: public RBOperation{
 public:
    GetRootOperation() {this->argc = 1;}
    std::string operator()(RBTree* tree, const std::vector<int>& arg) override;
};
#endif  // MODULES_RB_TREE_INCLUDE_RB_OPERATION_H_
