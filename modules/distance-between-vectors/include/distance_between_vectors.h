// Copyright 2020 Vladislav Golubev

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#include <vector>

class Metrics {
 private:
  std::vector<float> fst;
  std::vector<float> sec;

 public:
  Metrics();
  std::vector<float> getFirst();
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
