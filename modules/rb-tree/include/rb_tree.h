// Copyright 2020 Nazarov Vladislav

#ifndef MODULES_RB_TREE_INCLUDE_RB_TREE_H_
#define MODULES_RB_TREE_INCLUDE_RB_TREE_H_

#include <vector>

class Node {
 public:
   Node(int _data = 0, Node* _parent = nullptr, Node* _left = nullptr,
        Node* _right = nullptr, bool _color = false);
   Node(const Node& node);
   Node& operator=(const Node& node);
   bool operator==(const Node& node);
   bool operator!=(const Node& node);
 public:
   int data;
   Node* parent;
   Node* left;
   Node* right;
   bool color;  // false - Black, true - Red
};


#endif  // MODULES_RB_TREE_INCLUDE_RB_TREE_H_
