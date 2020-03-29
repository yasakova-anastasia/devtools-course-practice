// Copyright 2020 Maximova Irina

#ifndef MODULES_STATISTICS_INCLUDE_STATISTICS_H_
#define MODULES_STATISTICS_INCLUDE_STATISTICS_H_

#include <vector>

class Statistics {
 public:
  Statistics();
  explicit Statistics(const std::vector<double> probability);
  Statistics(const Statistics& s);

  std::vector<double> getProbability() const;
  void setProbability(const std::vector<double> probability);

 private:
  bool checkSumProbability(const std::vector<double> probability) const;
  std::vector<double> probability_;
};

#endif  // MODULES_STATISTICS_INCLUDE_STATISTICS_H_
