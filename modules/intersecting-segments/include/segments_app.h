// Copyright 2020 Maximova Irina

#ifndef MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_
#define MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_

#include <string>
#include <utility>
#include <vector>

class Segment_app {
  using Arguments = struct { std::vector<std::pair<double, double>> coord; };

 public:
  Segment_app();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);

  std::string calculateTriangleArea(const Arguments args) const;
  std::string relationPoint(const Arguments args) const;
  std::string segmentIntersection(const Arguments args) const;

  std::string message;
};

#endif  // MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_
