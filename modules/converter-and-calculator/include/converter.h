// Copyright 2020 Kornev Nikita

#ifndef MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_
#define MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_

#include <vector>
#include <stack>
using std::vector;
using std::stack;

class converter {
public:
  vector<bool> convert_dec_to_bin(const int& value);
};

#endif  // MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_