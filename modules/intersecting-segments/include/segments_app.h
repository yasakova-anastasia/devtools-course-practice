// Copyright 2020 Maximova Irina

#ifndef MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_
#define MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_

#include <string>

class Segment_app {
 public:
  Segment_app();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  std::string message_;
  bool validateNumberOfArguments(int argc, const char** argv);
  typedef struct {
    double x11;
    double y11;
    double x12;
    double y12;
    double x21;
    double y21;
    double x22;
    double y22;
  } Arguments;
};

#endif  // MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_
