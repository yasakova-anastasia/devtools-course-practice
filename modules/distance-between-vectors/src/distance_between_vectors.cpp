// Copyright 2020 Vladislav Golubev

#include <vector>
#include "../include/distance_between_vectors.h"

Metrics::Metrics() : fst(std::vector<float>(1)),
                     sec(std::vector<float>(1)) {}

std::vector<float> Metrics::getFirst() {
  return fst;
}

std::vector<float> Metrics::getSecond() {
  return sec;
}
