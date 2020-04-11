// Copyright 2020 Mazur Daniil
#include <cmath>
#include <vector>
#include <numeric>
#include <utility>
#include "../include/triangle_param.h"

Triangle::Triangle():
  a(0, 0), b(0, 0), c(0, 0) {}

Triangle::Triangle(const std::pair<double, double>& _a,
                   const std::pair<double, double>& _b,
                   const std::pair<double, double>& _c):
  a(_a), b(_b), c(_c) {}

Triangle::Triangle(const Triangle& _triangle):
  a(_triangle.a), b(_triangle.b), c(_triangle.c) {}

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

Triangle& Triangle::operator=(const Triangle& _triangle) {
    if (this != &_triangle) {
        a = _triangle.getTopA();
        b = _triangle.getTopB();
        c = _triangle.getTopC();
    }
    return *this;
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
                      std::pair<double, double> _top2) {
    return sqrt(pow(_top1.first - _top2.first, 2) +
                pow(_top1.second - _top2.second, 2));
}

double Triangle::cornA() {
    return acos((pow(side(a, c), 2) + pow(side(b, a), 2) -
                pow(side(b, c), 2)) / (2 * side(a, b) * side(a, c)));
}

double Triangle::cornB() {
    return acos((pow(side(a, b), 2) + pow(side(b, c), 2) -
                 pow(side(a, c), 2)) / (2 * side(a, b) * side(b, c)));
}

double Triangle::cornC() {
    return acos((pow(side(a, c), 2) + pow(side(b, c), 2) -
           pow(side(b, a), 2)) / (2 * side(a, c) * side(b, c)));
}

double Triangle::perimetr() {
    return (side(a, b) + side (b, c) + side (a, c));
}

double Triangle::square() {
    double temp = perimetr() / 2;
    return sqrt(temp * (temp - side(a, b)) *
           (temp - side(b, c)) * (temp - side(a, c)));
}
