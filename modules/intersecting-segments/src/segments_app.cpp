// Copyright 2020 Maximova Irina

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/segments_app.h"
#include "include/segments.h"

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
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    args.x11 = parseDouble(argv[1]);
    args.y11 = parseDouble(argv[2]);
    args.x12 = parseDouble(argv[3]);
    args.y12 = parseDouble(argv[4]);
    args.x21 = parseDouble(argv[5]);
    args.y21 = parseDouble(argv[6]);
    args.x22 = parseDouble(argv[7]);
    args.y22 = parseDouble(argv[8]);
  }
  catch (std::string& str) {
    return str;
  }

  Segment s1(args.x11, args.y11, args.x12, args.y12);
  Segment s2(args.x21, args.y21, args.x22, args.y22);

  std::ostringstream stream;

  bool intersect = s1.isIntersect(&s2);
  if (intersect)
    stream << "Segments do intersect";
  else
    stream << "Segments do not intersect";

  message_ = stream.str();
  return message_;
}
