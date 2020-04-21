// Copyright 2020 Maximova Irina

#include "include/statistics.h"

#include <math.h>
#include <stdbool.h>

#include <limits>
#include <string>
#include <vector>

const double eps = std::numeric_limits<double>::epsilon();

int Statistics::checkProbability(Map rand_var) const {
  double sum_probabilities = 0.0;
  for (const auto& val : rand_var) {
    if (val.second < 0) return -1;
    sum_probabilities += val.second;
  }
  return (sum_probabilities > 1 - eps && sum_probabilities < 1 + eps) ? 1 : 0;
}

Statistics::Statistics() {}

Statistics::Statistics(Map rand_var) {
  int resCheck = checkProbability(rand_var);
  if (resCheck == 0)
    throw std::string("The sum of the probabilities must be equal Unit");
  else if (resCheck == -1)
    throw std::string("The probability must be positive");
  else
    random_var = rand_var;
}

Statistics::Statistics(const Statistics& s) : random_var(s.getRandomVar()) {}

Map Statistics::getRandomVar() const { return random_var; }

void Statistics::setRandomVar(const Map rand_var) { random_var = rand_var; }

std::vector<int> Statistics::getValue() const {
  std::vector<int> result;
  for (const auto& val : random_var) result.push_back(val.first);
  return result;
}

std::vector<double> Statistics::getProbability() const {
  std::vector<double> result;
  for (const auto& val : random_var) result.push_back(val.second);
  return result;
}

Statistics& Statistics::operator=(const Statistics& s) {
  random_var = s.getRandomVar();
  return *this;
}

bool Statistics::operator==(const Statistics& s) const {
  return random_var == s.getRandomVar();
}

bool Statistics::operator!=(const Statistics& s) const { return !(*this == s); }

double Statistics::expectedValue() const {
  if (random_var.empty()) throw std::string("Empty data");
  double exp_val = 0.;
  for (const auto& val : random_var) exp_val += val.first * val.second;
  return exp_val;
}

double Statistics::moment(int order, double a) const {
  if (random_var.empty()) throw std::string("Empty data");
  if (order < 0) throw std::string("The order must be positive");

  double m = 0.;
  for (const auto& val : random_var)
    m += powl(val.first - a, order) * val.second;
  return m;
}

double Statistics::dispersion() const {
  return this->moment(2, this->expectedValue());
}
