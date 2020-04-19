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

class RBTree {
 public:
   RBTree();
   explicit RBTree(Node* node);
   explicit RBTree(const std::vector<int>& vec);
   RBTree(const RBTree& tree) = default;

   Node* GetRoot() const;
   Node* find(const int& data);
   void insert(Node* node);
   void remove(const int& data);
 private:
   void insertBalancing(Node* node);
   void swapNodes(Node* node1, Node* node2);
   void removeBalancing(Node* node);
   void leftRotate(Node* node);
   void rightRotate(Node* node);
 private:
   Node* _NIL;
   Node* _root;
};

#endif  // MODULES_RB_TREE_INCLUDE_RB_TREE_H_
