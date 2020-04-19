// Copyright 2020 Nazarov Vladislav

#include "include/rb_tree.h"

Node::Node(int _data, Node *_left, Node *_right, Node *_parent, bool _color) :
           data(_data), left(_left), right(_right),
           parent(_parent), color(_color) {}

Node::Node(const Node& node) : data(node.data), left(node.left),
           right(node.right), parent(node.parent), color(node.color) {}

Node& Node::operator=(const Node& node) {
    data = node.data;
    left = node.left;
    right = node.right;
    parent = node.parent;
    color = node.color;

    return *this;
}

bool Node::operator==(const Node& node) {
    if (data == node.data && left == node.left && right == node.right
        && parent == node.parent && color == node.color)
        return true;

    return false;
}

bool Node::operator!=(const Node& node) {
    return !(*this == node);
}
