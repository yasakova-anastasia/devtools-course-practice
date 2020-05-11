// Copyright 2020 Isaev Ilya

#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include "include/rb_operation.h"

RBOperation* RBOperation::makeOperation(std::string op) {
    if (op == "insert") {
        return new InsertOperation;
    }
    if (op == "find") {
        return new FindOperation;
    }
    if (op == "remove") {
        return new RemoveOperation;
    }
    if (op == "getRoot") {
        return new GetRootOperation;
    }
    throw std::invalid_argument("Bad arguments!");
}

int RBOperation::isNIL(Node* node) {
    return node->color == Color::black &&
        node->right == nullptr && node->left == nullptr;
}

std::string InsertOperation::operator()(RBTree* tree,
    const std::vector<int>& arg) {
    tree->insert(new Node{arg[0]});
    return "";
}
std::string FindOperation::operator()(RBTree* tree,
    const std::vector<int>& arg) {
        auto found = tree->find(arg[0]);
        std::stringstream stream;
        if (!isNIL(found)) {
            stream << "(" << arg[0] << " is found) ";
            return stream.str();
        } else {
            stream << "(" << arg[0] << " is not found) ";
            return stream.str();
        }
}
std::string RemoveOperation::operator()(RBTree* tree,
    const std::vector<int>& arg) {
    try {
        tree->remove(arg[0]);
        return "";
    } catch(std::exception& ex) {
        return "(" + std::string(ex.what()) + ")";
    }
}

std::string GetRootOperation::operator()(RBTree* tree,
    const std::vector<int>& arg) {
    auto root = tree->getRoot();
    std::stringstream stream;
    if (!isNIL(root)) {
        stream << "(Root value: " << root->data << ")";
        return stream.str();
    } else {
        stream << "(Tree is empty)";
        return stream.str();
    }
}
