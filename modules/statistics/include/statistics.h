// Copyright 2020 Maximova Irina

#ifndef MODULES_STATISTICS_INCLUDE_STATISTICS_H_
#define MODULES_STATISTICS_INCLUDE_STATISTICS_H_

#include <vector>

class Statistics {
 public:
  explicit Statistics(const std::vector<double> _probability);

  std::vector<double> getProbability() const;

 private:
  bool checkSumProbability(const std::vector<double> probability) const;
  std::vector<double> probability;
};

#endif  // MODULES_STATISTICS_INCLUDE_STATISTICS_H_
