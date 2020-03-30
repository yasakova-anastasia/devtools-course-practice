// Copyright 2020 Maximova Irina

#ifndef MODULES_STATISTICS_INCLUDE_STATISTICS_H_
#define MODULES_STATISTICS_INCLUDE_STATISTICS_H_

#include <map>
#include <vector>

typedef std::map<int, double> Map;

class Statistics {
 public:
  Statistics();
  explicit Statistics(Map rand_var);
  Statistics(const Statistics& s);

  Map getRandomVar() const;
  void setRandomVar(Map rand_var);
  std::vector<int> getValue() const;
  std::vector<double> getProbability() const;

  Statistics& operator=(const Statistics& s);
  bool Statistics::operator==(const Statistics& s) const;
  bool Statistics::operator!=(const Statistics& s) const;

  double expectedValue() const;
  double dispersion() const;
  double moment(int order, double a) const;

 private:
  int checkProbability(Map rand_var) const;
  Map random_var;
};

#endif  // MODULES_STATISTICS_INCLUDE_STATISTICS_H_
