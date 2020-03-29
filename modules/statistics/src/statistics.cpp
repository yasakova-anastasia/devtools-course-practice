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

Statistics::Statistics() {}

Statistics::Statistics(const std::vector<double> probability) {
  if (checkSumProbability(probability) == false)
    throw std::string("The sum of the probabilities must be equal 1");

  probability_ = probability;
}

Statistics::Statistics(const Statistics& s)
    : probability_(s.getProbability()) {}

std::vector<double> Statistics::getProbability() const { return probability_; }

void Statistics::setProbability(const std::vector<double> probability) {
  probability_ = probability;
}

Statistics& Statistics::operator=(const Statistics& s) {
  probability_ = s.getProbability();
  return *this;
}

bool Statistics::operator==(const Statistics& s) const {
  return probability_ == s.getProbability();
}

bool Statistics::operator!=(const Statistics& s) const { return !(*this == s); }
