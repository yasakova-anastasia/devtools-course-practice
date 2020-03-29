// Copyright 2020 Maximova Irina

#include "include/statistics.h"

#include <limits>
#include <string>
#include <vector>

const double eps = std::numeric_limits<double>::epsilon();

int Statistics::checkProbability(const std::vector<double> probability) const {
  double sum = 0.0;
  for (const auto& i : probability) {
    if (i < 0) return -1;
    sum += i;
  }
  return (sum > 1 - eps && sum < 1 + eps) ? 1 : 0;
}

Statistics::Statistics() {}

Statistics::Statistics(const std::vector<double> probability) {
  int resCheck = checkProbability(probability);
  if (resCheck == 0)
    throw std::string("The sum of the probabilities must be equal Unit");
  else if (resCheck == -1)
    throw std::string("The probability must be positive");
  else
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

double Statistics::expectedValue() const {
  double exp_val = 0.;
  for (size_t i = 0; i < probability_.size(); ++i)
    exp_val += i * probability_[i];
  return exp_val;
}
