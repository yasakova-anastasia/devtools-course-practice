// Copyright 2020 Maximova Irina

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/segments_app.h"

Segment_app::Segment_app() : message_("") {}

void Segment_app::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is an intersecting segments application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <x11> <y11> " +
    "<x12> <y12> \n\n" + " <x21> <y21> " +
    "<x22> <y22> \n\n" +

    "Where all arguments are double-precision numbers\n";
}

bool Segment_app::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 9) {
    help(argv[0], "ERROR: Should be 8 arguments.\n\n");
    return false;
  }
  return true;
}

double parseDouble(const char* arg) {
  char* end;
  double value = strtod(arg, &end);

  if (end[0]) {
    throw std::string("Wrong number format!");
  }

  return value;
}

std::string Segment_app::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  std::ostringstream stream;

  message_ = stream.str();

  return message_;
}
