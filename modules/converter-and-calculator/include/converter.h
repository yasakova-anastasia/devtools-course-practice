// Copyright 2020 Kornev Nikita

#ifndef MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_
#define MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_

#include <vector>
#include <stack>
using std::vector;
using std::stack;

class converter {
public:
  vector<int> convert_dec_to_smaller(const int& value, const int& system);
  int convert_smaller_to_dec(const vector<int>& value, const int& system);

  vector<int> convert_dec_to_oct(const int& value);
};

#endif  // MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_