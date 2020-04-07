// Copyright 2020 Kornev Nikita

#include <iostream>
#include "include/converter.h"
using namespace std;

vector<int> converter::convert_dec_to_smaller(const vector<int>& value, const int& target_system)
{
  int temp_value;
  stack<int> temp_stack;
  vector<int> res;
  int remainder;

  parse(value, temp_value);

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

vector<int> converter::convert_smaller_to_dec(const vector<int>& value, const int& this_system) {
  int temp = 0;

  for (auto i = 0; i < value.size(); i++) {
    temp += value[i] * static_cast<int>(pow(this_system, value.size() - i - 1));
  }

  vector<int> res;
  parse(temp, res);

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

int converter::convert_hex_to_dec(const vector<char>& value)
{
  int res = 0;
  int temp = 0;

  for (auto i = 0; i < value.size(); i++) {
    if (isdigit(value[i])) {
      temp = atoi(string({ (char)value[i] }).c_str());
    }
    else {
      if (value[i] == 'A')
        temp = 10;
      if (value[i] == 'B')
        temp = 11;
      if (value[i] == 'C')
        temp = 12;
      if (value[i] == 'D')
        temp = 13;
      if (value[i] == 'E')
        temp = 14;
      if (value[i] == 'F')
        temp = 15;
    }

    res += temp * static_cast<int>(pow(16, value.size() - i - 1));
  }

  return res;
}

vector<int> converter::convert(const vector<int>& value, const int& this_system, const int& target_system)
{
  auto temp = value;
  if (this_system != 10)
      temp = convert_smaller_to_dec(value, this_system);
  auto res = convert_dec_to_smaller(temp, target_system);
  return res;
}

void converter::parse(const vector<int>& value, int& res)
{
  string temp = "";
  for (auto i = 0; i < value.size(); i++)
    temp += value[i];
  res = atoi(temp.c_str());
}

void converter::parse(const int& value, vector<int>& res)
{
  string temp = "";

  temp += value;
  for (auto i = 0; i < temp.size(); i++)
    res.push_back(temp[i]);
}

