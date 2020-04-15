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
  Metrics(const Metrics&) = default;
  Metrics(const std::vector<float>& _fst, const std::vector<float>& _sec);

  std::vector<float> getFirst();
  std::vector<float> getSecond();
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
