// Copyright 2020 Guschin Alexander

#include <time.h>
#include <vector>
#include <random>
#include "include/radix_sort.h"



void Fill_Random(std::vector<std::int32_t>* req_vec) {
  std::mt19937 gen(time(0));
  int size = req_vec->size();
  for (int i = 0; i < size; ++i) {
    std::int32_t tmp = static_cast<std::int32_t>(gen());
    if (tmp == 0) ++tmp;
    (*req_vec)[i] = tmp;
  }
}
