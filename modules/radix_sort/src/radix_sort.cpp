// Copyright 2020 Guschin Alexander

#include <time.h>
#include <vector>
#include <random>
#include "include/radix_sort.h"



void FillRandom(std::vector<std::int32_t>* vec_ptr) {
  std::mt19937 gen(time(0));
  std::int32_t size = vec_ptr->size();
  for (std::int32_t i = 0; i < size; ++i) {
    std::int32_t tmp = static_cast<std::int32_t>(gen());
    if (tmp == 0) ++tmp;
    (*vec_ptr)[i] = tmp;
  }
}

bool IsSorted(const std::vector<std::int32_t>& vec_ref) {
  std::int32_t size = vec_ref.size();
  for (std::int32_t i = 1; i < size; ++i)
    if (vec_ref[i] < vec_ref[i - 1]) return false;

  return true;
}

std::vector<std::int32_t> RadixSort(const std::vector<std::int32_t>& vec_ref) {
  return std::vector<std::int32_t>();
}
