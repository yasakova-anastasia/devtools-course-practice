// Copyright 2020 Kukushkina Ksenia

#include "include/segments.h"

Segment::Segment(double _x1, double _y1, double _x2, double _y2) {
  x1 = _x1;
  y1 = _y1;
  x2 = _x2;
  y2 = _y2;
}

double Segment::area(double x, double y) {
  return (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
}

bool Segment::isIntersect(Segment* A) {
  return 1;
}
