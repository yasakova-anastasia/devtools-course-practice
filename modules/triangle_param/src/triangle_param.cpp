// Copyright 2020 Mazur Daniil
#include <cmath>
#include <vector>
#include <numeric>
#include <utility>
#include <string>
#include "../include/triangle_param.h"

Triangle::Triangle():
  a(0, 0), b(1, 0), c(0, 1) {}

Triangle::Triangle(const std::pair<double, double>& _a,
  const std::pair<double, double>& _b,
  const std::pair<double, double>& _c) {
  if ((_a == _b) || (_b == _c) || (_a == _c) || ((_a.first == _b.first) &&
    (_b.first == _c.first)) || ((_a.second == _b.second) &&
    (_b.second == _c.second))) {
    throw static_cast<std::string>(
      "Invalid params");
  } else {
    a = _a;
    b = _b;
    c = _c;
  }
}

std::pair<double, double> Triangle::getTopA() const {
  return a;
}

std::pair<double, double> Triangle::getTopB() const {
  return b;
}

std::pair<double, double> Triangle::getTopC() const {
  return c;
}

void Triangle::setTopA(const std::pair<double, double>& _top) {
  a = _top;
}

void Triangle::setTopB(const std::pair<double, double>& _top) {
  b = _top;
}

void Triangle::setTopC(const std::pair<double, double>& _top) {
  c = _top;
}

bool Triangle::operator== (const Triangle& _triangle) const {
  if ((a == _triangle.getTopA()) &&
    (b == _triangle.getTopB()) &&
      (c == _triangle.getTopC())) {
      return true;
  } else {
      return false;
    }
}

bool Triangle::operator!= (const Triangle& _triangle) const {
  return !(*this == _triangle);
}

double Triangle::side(std::pair<double, double> _top1,
  std::pair<double, double> _top2) const {
  return sqrt(pow(_top1.first - _top2.first, 2) +
    pow(_top1.second - _top2.second, 2));
}

double Triangle::cornA() const {
  return acos((pow(side(a, c), 2) + pow(side(b, a), 2) -
    pow(side(b, c), 2)) / (2 * side(a, b) * side(a, c)));
}

double Triangle::cornB() const {
  return acos((pow(side(a, b), 2) + pow(side(b, c), 2) -
    pow(side(a, c), 2)) / (2 * side(a, b) * side(b, c)));
}

double Triangle::cornC() const {
  return acos((pow(side(a, c), 2) + pow(side(b, c), 2) -
    pow(side(b, a), 2)) / (2 * side(a, c) * side(b, c)));
}

double Triangle::perimetr() const {
  return (side(a, b) + side (b, c) + side (a, c));
}

double Triangle::square() const {
  double temp = perimetr() / 2;
  return sqrt(temp * (temp - side(a, b)) *
    (temp - side(b, c)) * (temp - side(a, c)));
}
