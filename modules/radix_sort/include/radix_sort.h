// Copyright 2020 Guschin Alexander

#ifndef MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
#define MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_

#include <time.h>
#include <vector>
#include <random>


void FillRandom(std::vector<std::int32_t>* vec_ptr);
bool IsSorted(const std::vector<std::int32_t>& vec_ref);
std::vector<std::int32_t> RadixSort(std::vector<std::int32_t> vec);

#endif  // MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
