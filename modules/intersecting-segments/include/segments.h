// Copyright 2020 Kukushkina Ksenia & Maximova Irina

#ifndef MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_
#define MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_

#include <utility>

using dd = std::pair<double, double>;

class Segment {
 public:
  Segment(double _x1, double _y1, double _x2, double _y2);
  Segment(dd coord_1, dd coord_2);

  double area(double x, double y);  // double oriented triangle area
  bool isIntersect(Segment A);

 private:
  double x1;
  double y1;
  double x2;
  double y2;
};

#endif  // MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_H_
