// Copyright 2020 Pauzin Leonid
#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_
#define MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_

#include <vector>
#include <algorithm>

template <typename T>
class THeap {
 public:
  THeap() = default;
  void Push(T value);

 private:
  std::vector<T> vec;
  void Emersion();
  int GetParent(int child);
};

template<typename T>
void THeap<T>::Push(T value) {
  vec.push_back(value);
  Emersion();
}

template<typename T>
void THeap<T>::Emersion() {
  int child = vec.size() - 1;
  int parent = GetParent(child);

  while (vec[child] > vec[parent] && child >= 0 && parent >= 0) {
    std::swap(child, parent);
    child = parent;
    parent = GetParent(child);
  }
}

template <typename T>
int THeap<T>::GetParent(int child) {
  if (child > 0 && child % 2 == 0)
    return child / 2 - 1;
  else
    return child / 2;
}


#endif  // MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_
