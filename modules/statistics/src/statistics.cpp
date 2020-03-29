// Copyright 2020 Maximova Irina

#include "include/statistics.h"

#include <stdbool.h>
#include <limits>
#include <string>
#include <vector>

const double eps = std::numeric_limits<double>::epsilon();

bool Statistics::checkSumProbability(
    const std::vector<double> probability) const {
  double sum = 0.0;
  for (const auto& i : probability) sum += i;
  return sum < 1 + eps && sum > 1 - eps;
}

Statistics::Statistics(const std::vector<double> _probability) {
  if (checkSumProbability(_probability) == false)
    throw std::string("The sum of the probabilities must be equal 1");

  probability = _probability;
}

std::vector<double> Statistics::getProbability() const { return probability; }
