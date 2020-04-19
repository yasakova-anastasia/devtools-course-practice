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

RBTree::RBTree() : _NIL(new Node{}), _root(_NIL) {}

RBTree::RBTree(Node *node) : _NIL(new Node{}), _root(node) {
        _root->left = _NIL;
        _root->right = _NIL;
        _root->parent = _NIL;
    }

RBTree::RBTree(const std::vector<int>& vec) :
               _NIL(new Node{}), _root(_NIL) {
    for (int data : vec) {
        Node *node = new Node{data};
        insert(node);
    }
}

Node* RBTree::GetRoot() const {
    return _root;
}

Node* RBTree::find(const int& data) {
    Node* current = _root;

    while (current != _NIL) {
        if (data == current->data)
            return current;
        else if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return _NIL;
}

void RBTree::insert(Node *node) {
    if (find(node->data) != _NIL)
        throw "Node already in tree";

    Node *tmp = _NIL;
    Node *tmp2 = _root;

    while (tmp2 != _NIL) {
        tmp = tmp2;
        if (node->data < tmp2->data)
            tmp2 = tmp2->left;
        else
            tmp2 = tmp2->right;
    }

    node->parent = tmp;

    if (tmp == _NIL)
        _root = node;
    else if (node->data < tmp->data)
        tmp->left = node;
    else
        tmp->right = node;

    node->left = _NIL;
    node->right = _NIL;
    node->color = true;

    insertBalancing(node);
}

void RBTree::remove(const int& data) {
    Node* find_node = find(data);
    if (find_node == _NIL)
        throw "No that data in tree";

    Node *node = find_node;
    Node *tmp = node;
    Node *tmp2;

    bool tmp_original_color = tmp->color;

    if (node->left == _NIL) {
        tmp2 = node->right;
        swapNodes(node, node->right);
    } else if (node->right == _NIL) {
        tmp2 = node->left;
        swapNodes(node, node->left);
    } else {
        tmp = node->right;
        while (tmp->left != _NIL)
            tmp = tmp->left;

        tmp_original_color = tmp->color;
        tmp2 = tmp->right;

        if (tmp->parent == node) {
            tmp2->parent = tmp;
        } else {
            swapNodes(tmp, tmp->right);
            tmp->right = node->right;
            tmp->right->parent = tmp;
        }

        swapNodes(node, tmp);
        tmp->left = node->left;
        tmp->left->parent = tmp;
        tmp->color = node->color;
    }

    if (tmp_original_color == false)
        removeBalancing(tmp2);
}

void RBTree::insertBalancing(Node *node) {
    while (node->parent->color == true) {
        if (node->parent == node->parent->parent->left) {
            Node *tmp = node->parent->parent->right;

            if (tmp->color == true) {
                node->parent->color = false;
                tmp->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                rightRotate(node->parent->parent);
            }
        } else {
            Node *tmp = node->parent->parent->left;

            if (tmp->color == true) {
                node->parent->color = false;
                tmp->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                leftRotate(node->parent->parent);
            }
        }
    }

    _root->color = false;
}

void RBTree::swapNodes(Node *node1, Node *node2) {
    if (node1->parent == _NIL)
        _root = node2;
    else if (node1 == node1->parent->left)
        node1->parent->left = node2;
    else
        node1->parent->right = node2;

    node2->parent = node1->parent;
}

void RBTree::removeBalancing(Node *node) {
    while (node != _root && node->color == false) {
        if (node == node->parent->left) {
            Node *tmp = node->parent->right;

            if (tmp->color == true) {
                tmp->color = false;
                node->parent->color = true;
                leftRotate(node->parent);
                tmp = node->parent->right;
            }

            if (tmp->left->color == false && tmp->right->color == false) {
                tmp->color = true;
                node = node->parent;
            } else {
                if (tmp->right->color == false) {
                    tmp->left->color = false;
                    tmp->color = true;
                    rightRotate(tmp);
                    tmp = node->parent->right;
                }
                tmp->color = node->parent->color;
                node->parent->color = false;
                tmp->right->color = false;
                leftRotate(node->parent);
                node = _root;
            }
        } else {
            Node *tmp = node->parent->left;

            if (tmp->color == true) {
                tmp->color = false;
                node->parent->color = true;
                rightRotate(node->parent);
                tmp = node->parent->left;
            }

            if (tmp->right->color == false && tmp->left->color == false) {
                tmp->color = true;
                node = node->parent;
            } else {
                if (tmp->left->color == false) {
                    tmp->right->color = false;
                    tmp->color = true;
                    leftRotate(tmp);
                    tmp = node->parent->left;
                }
                tmp->color = node->parent->color;
                node->parent->color = false;
                tmp->left->color = false;
                rightRotate(node->parent);
                node = _root;
            }
        }
    }

    node->color = false;
}

void RBTree::leftRotate(Node *node) {
    Node *tmp = node->right;
    node->right = tmp->left;

    if (tmp->left != _NIL)
        tmp->left->parent = node;

    tmp->parent = node->parent;

    if (node->parent == _NIL)
        _root = tmp;
    else if (node == node->parent->left)
        node->parent->left = tmp;
    else
        node->parent->right = tmp;

    tmp->left = node;
    node->parent = tmp;
}

void RBTree::rightRotate(Node *node) {
    Node *tmp = node->left;
    node->left = tmp->right;

    if (tmp->right != _NIL)
        tmp->right->parent = node;

    tmp->parent = node->parent;

    if (node->parent == _NIL)
        _root = tmp;
    else if (node == node->parent->right)
        node->parent->right = tmp;
    else
        node->parent->left = tmp;

    tmp->right = node;
    node->parent = tmp;
}
