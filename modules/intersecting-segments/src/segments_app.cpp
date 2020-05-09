// Copyright 2020 Maximova Irina

#include "include/segments_app.h"

#include <cmath>
#include <sstream>
#include <string>

#include "include/segments.h"

Segment_app::Segment_app() : message("") {}

void Segment_app::help(const char* appname, const char* _message) {
  message = std::string(_message) +
            "This is an intersecting segments application.\n" +
            "Please provide arguments in the following format:\n\n" + "  $ " +
            appname + " <number_operation> <points_1_x> " +
            "<points_1_y> <points_2_x> " + "<points_2_y>  ...\n\n\n" +
            "Where <number_operation>:\n\t" +
            "1 - Calculate triangle area. Number coordinates = 3.\n\t" +
            "2 - Determination of the point position regarding the vector." +
            "Number coordinates = 3. First coordinate - point coordinate.\n\t" +
            "3 - Check segments for intersection. Number coordinates = 4.\n" +
            "All coordinates are double-precision numbers\n";
}

bool Segment_app::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  }

  bool validate = false;
  int operation = std::stoi(argv[1]);
  if (operation == 1 || operation == 2) {
    validate = (argc == 8);
  } else if (operation == 3) {
    validate = (argc == 10);
  } else {
    message = "ERROR: Number operation must be 1 or 2 or 3.";
    return false;
  }

  if (!validate) message = "ERROR: Incurrect number arguments.";
  return validate;
}

std::string Segment_app::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message;
  }

  try {
    dd temp_pair;
    for (int i = 2; i < argc; i += 2) {
      temp_pair = std::make_pair(std::stod(argv[i]), std::stod(argv[i + 1]));
      coord.push_back(temp_pair);
    }
  } catch (std::string& str) {
    return str;
  }

  std::ostringstream stream;  //////////////////

  switch (std::stoi(argv[1])) {
    case 1: {
      calculateTriangleArea();
      break;
    }
    case 2: {
      relationPoint();
      break;
    }
    case 3: {
      segmentIntersection();
      break;
    }
  }

  stream << message;  /////////////////////////
  return message;
}

void Segment_app::calculateTriangleArea() {
  double x = coord[0].first;
  double y = coord[0].second;
  Segment line(coord[1], coord[2]);

  message = "Triangle area = " + std::to_string(std::abs(line.area(x, y)));
}

void Segment_app::relationPoint() {
  double x = coord[0].first;
  double y = coord[0].second;
  Segment line(coord[1], coord[2]);

  double area = line.area(x, y);
  if (area < 0)
    message = "Point to the right of the vector.";
  else if (area > 0)
    message = "Point to the left of the vector.";
  else
    message = "Point on the vector.";
}

void Segment_app::segmentIntersection() {
  Segment line_1(coord[0], coord[1]);
  Segment line_2(coord[2], coord[3]);

  if (line_1.isIntersect(line_2))
    message = "Segments do intersect";
  else
    message = "Segments do not intersect";
}
