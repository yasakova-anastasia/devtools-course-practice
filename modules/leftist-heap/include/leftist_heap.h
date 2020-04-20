// Copyright 2020 Vlasov Andrey

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_

class Node {
 public:
  explicit Node(const int key);
  static Node* merge(Node* x, Node* y);

  int key, dist;
  Node* left, * right;
};

#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_H_
