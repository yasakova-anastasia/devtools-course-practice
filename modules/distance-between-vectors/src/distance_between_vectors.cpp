// Copyright 2020 Vladislav Golubev

#include <vector>
#include "../include/distance_between_vectors.h"

Metrics::Metrics() : fst(std::vector<float>(1)),
                     sec(std::vector<float>(1)) {}

Metrics::Metrics(const std::vector<float>& _fst,
                 const std::vector<float>& _sec) {
  if (_fst.size() != _sec.size()) {
    throw "vectors of different dimensions";
   }
  fst = _fst;
  sec = _sec;
}

std::vector<float> Metrics::getFirst() {
  return fst;
}

std::vector<float> Metrics::getSecond() {
  return sec;
}
