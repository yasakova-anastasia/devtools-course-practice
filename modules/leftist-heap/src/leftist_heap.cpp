// Copyright 2020 Vlasov Andrey

#include "include/leftist_heap.h"

#include <string>

Node::Node(const int _key) {
  key = _key;
  dist = 0;
  left = NULL;
  right = NULL;
}

Node* Node::merge(Node* x, Node* y) {
  if (x == NULL) {
    return y;
  }
  if (y == NULL) {
    return x;
  }

  if (x->key > y->key) {
    Node* temp = x;
    x = y;
    y = temp;
  }

  x->right = merge(x->right, y);

  if (x->left == NULL) {
    x->left = x->right;
    x->right = NULL;
  } else {
    if (x->left->dist < x->right->dist) {
      Node* temp = x->left;
      x->left = x->right;
      x->right = temp;
    }
    x->dist = x->right->dist + 1;
  }

  return x;
}
