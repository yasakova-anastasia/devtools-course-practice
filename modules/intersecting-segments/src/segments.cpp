// Copyright 2020 Kukushkina Ksenia

#include <cmath>
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
  double s1, s2, s3, s4;
  s1 = A->area(x1, y1);
  s2 = A->area(x2, y2);
  s3 = area(A->x1, A->y1);
  s4 = area(A->x2, A->y2);
  if (s1 * s2 <= 0 && s3 * s4 <= 0)
    return true;
  return false;
}
