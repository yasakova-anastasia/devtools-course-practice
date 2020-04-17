// Copyright 2020 Guschin Alexander

#ifndef MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
#define MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_

#include <time.h>
#include <vector>
#include <random>


void FillRandom(std::vector<std::int32_t>* vector_ptr);
bool IsSorted(const std::vector<std::int32_t>& vector_ref);
std::vector<std::int32_t> RadixSort(std::vector<std::int32_t> vector);

#endif  // MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
