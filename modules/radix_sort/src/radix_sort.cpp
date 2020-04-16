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

std::vector<std::int32_t> RadixSort(std::vector<std::int32_t> vec) {
  std::int32_t size = vec.size();
  std::vector<std::int32_t> res_vec(size);
  std::uint8_t* ptr = reinterpret_cast<std::uint8_t*>(&vec[0]);

  for (std::int32_t k = 0; k < 4; ++k) {
    std::int32_t count[256] = {0};
    for (std::int32_t i = 0; i < size; ++i) count[*(ptr + k + i * 4)]++;

    std::int32_t shift = 0;
    if (k == 3) {
      for (std::int32_t i = 128; i < 256; ++i) shift += count[i];
    }

    std::int32_t sum = 0;
    for (std::int32_t i = 0; i < 256; ++i) {
      std::int32_t tmp = count[i];
      count[i] = sum;
      sum += tmp;
    }

    for (std::int32_t i = 0; i < size; ++i) {
      res_vec[(count[*(ptr + k + i * 4)] + shift) % size] = vec[i];
      count[*(ptr + k + i * 4)]++;
    }

    vec = res_vec;
  }
  return res_vec;
}
