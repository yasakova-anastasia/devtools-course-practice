// Copyright 2020 Maximova Irina

#include <string>

#include "include/segments_app.h"

Segment_app::Segment_app() : message_("") {}

void Segment_app::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a intersecting segments application.\n\n" +
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
