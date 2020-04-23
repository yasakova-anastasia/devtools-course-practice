// Copyright 2020 Pauzin Leonid
#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_
#define MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_

#include <vector>

template <typename T>
 class THeap {
public:
  THeap() = default;

 private:
  std::vector<T> vec;

};

#endif MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_
