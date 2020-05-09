// Copyright 2020 Maximova Irina

#ifndef MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_
#define MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_

#include <string>
#include <utility>
#include <vector>

using dd = std::pair<double, double>;

class Segment_app {
 public:
  Segment_app();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);

  void calculateTriangleArea();
  void relationPoint();
  void segmentIntersection();

  std::string message;
  std::vector<dd> coord;
};

#endif  // MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_
