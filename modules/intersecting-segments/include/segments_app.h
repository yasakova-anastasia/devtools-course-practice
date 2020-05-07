// Copyright 2020 Maximova Irina

#ifndef MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_
#define MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_

#include <string>

class Segment_app {
 public:
  Segment_app();

 private:
  void help(const char* appname, const char* message = "");
  std::string message_;
  bool validateNumberOfArguments(int argc, const char** argv);
};

#endif  // MODULES_INTERSECTING_SEGMENTS_INCLUDE_SEGMENTS_APP_H_
