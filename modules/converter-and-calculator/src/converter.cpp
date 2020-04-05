// Copyright 2020 Kornev Nikita

#include "include/converter.h"
#include <iostream>
using namespace std;

vector<bool> converter::convert_dec_to_bin(const int& value)
{
  int temp_value = value;
  stack<bool> temp_stack;
  vector<bool> res;
  bool remainder;

  while (temp_value > 0) {
    remainder = temp_value % 2;
    temp_stack.push(remainder);
    temp_value /= 2;
  }

  auto stack_size = temp_stack.size();

  for (auto i = 0; i < stack_size; i++) {
    remainder = temp_stack.top();
    res.push_back(remainder);
    temp_stack.pop();
  }
  return res;
}

int converter::convert_bin_to_dec(const vector<bool>& value) {
  int res = 0;

  for (auto i = 0; i < value.size(); i++) {
    res += value[i] * static_cast<int>(pow(2, value.size() - i - 1));
  }

  return res;
}
