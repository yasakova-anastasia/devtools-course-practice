// Copyright 2020 Kornev Nikita

#include "include/converter.h"
#include <iostream>
using namespace std;

vector<int> converter::convert_dec_to_smaller(const int& value, const int& target_system)
{
  int temp_value = value;
  stack<int> temp_stack;
  vector<int> res;
  int remainder;

  while (temp_value > 0) {
    remainder = temp_value % target_system;
    temp_stack.push(remainder);
    temp_value /= target_system;
  }

  auto stack_size = temp_stack.size();

  for (auto i = 0; i < stack_size; i++) {
    remainder = temp_stack.top();
    res.push_back(remainder);
    temp_stack.pop();
  }
  return res;
}

int converter::convert_smaller_to_dec(const vector<int>& value, const int& this_system) {
  int res = 0;

  for (auto i = 0; i < value.size(); i++) {
    res += value[i] * static_cast<int>(pow(this_system, value.size() - i - 1));
  }

  return res;
}

vector<char> converter::convert_dec_to_hex(const int& value)
{
  int temp_value = value;
  stack<char> temp_stack;
  vector<char> res;
  int remainder;
  char element;

  while (temp_value > 0) {
    remainder = temp_value % 16;

    if (remainder > 9) {
      if (remainder == 10)
        element = 'A';
      if (remainder == 11)
        element = 'B';
      if (remainder == 12)
        element = 'C';
      if (remainder == 13)
        element = 'D';
      if (remainder == 14)
        element = 'E';
      if (remainder == 15)
        element = 'F';
    }
    else {
      element = remainder + '0';
    }

    temp_stack.push(element);
    temp_value /= 16;
  }

  auto stack_size = temp_stack.size();

  for (auto i = 0; i < stack_size; i++) {
    element = temp_stack.top();
    res.push_back(element);
    temp_stack.pop();
  }
  return res;
}