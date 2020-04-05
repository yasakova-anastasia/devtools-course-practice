// Copyright 2020 Kornev Nikita

#include "include/converter.h"
#include <iostream>
using namespace std;

vector<int> converter::convert_dec_to_smaller(const int& value, const int& system)
{
  int temp_value = value;
  stack<int> temp_stack;
  vector<int> res;
  int remainder;

  while (temp_value > 0) {
    remainder = temp_value % system;
    temp_stack.push(remainder);
    temp_value /= system;
  }

  auto stack_size = temp_stack.size();

  for (auto i = 0; i < stack_size; i++) {
    remainder = temp_stack.top();
    res.push_back(remainder);
    temp_stack.pop();
  }
  return res;
}

int converter::convert_smaller_to_dec(const vector<int>& value, const int& system) {
  int res = 0;

  for (auto i = 0; i < value.size(); i++) {
    res += value[i] * static_cast<int>(pow(system, value.size() - i - 1));
  }

  return res;
}

vector<int> converter::convert_dec_to_oct(const int& value)
{
  int temp_value = value;
  stack<int> temp_stack;
  vector<int> res;
  int remainder;

  while (temp_value > 0) {
    remainder = temp_value % 8;
    temp_stack.push(remainder);
    temp_value /= 8;
  }

  auto stack_size = temp_stack.size();

  for (auto i = 0; i < stack_size; i++) {
    remainder = temp_stack.top();
    res.push_back(remainder);
    temp_stack.pop();
  }
  return res;
}
