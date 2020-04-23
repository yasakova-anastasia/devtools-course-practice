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
  T Remove();

 private:
  std::vector<T> vec;
  void Emersion();
  int GetParent(int child);
  void Immersion();
  int GetLeftChild(int parent);
  int GetRightChild(int parent);
  void swap(int child, int parent);
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

template <typename T>
T THeap<T>::Remove() {
  if (vec.size() == 0) {
    throw "Nothing to remove";
  }
  int child = vec.size() - 1;
  swap(child, 0);
  T value = vec.back();
  vec.pop_back();
  Immersion();
  return value;  
}

template <typename T>
void THeap<T>::swap(int child, int parent) {
  std::swap(vec[child], vec[parent]);
}

template <typename T>
void THeap<T>::Immersion() {
  int parent = 0;

  while (true) {
    int left = GetLeftChild(parent);
    int right = GetRightChild(parent);
    int length = vec.size();
    int largest = parent;

    if ((left < length) && (vec[left] > vec[largest]))
      largest = left;
    if ((right < length) && (vec[right] > vec[largest]))
      largest = right;
    if (largest != parent) {
      std::swap(largest, parent);
      parent = largest;
    }
    else {
      break;
    }
  }
}

template <typename T>
int THeap<T>::GetLeftChild(int parent) {
  return 2 * parent + 1;
}

template <typename T>
int THeap<T>::GetRightChild(int parent) {
  return 2 * parent + 2;
}


#endif  // MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_
