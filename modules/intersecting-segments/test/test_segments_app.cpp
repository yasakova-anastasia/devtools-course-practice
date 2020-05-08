// Copyright 2020 Maximova Irina

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/segments_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Segment_app_test : public ::testing::Test {
 protected:
  void Act(vector<string> args_) {
    vector<const char*> options;

    options.push_back("appname");
    for (size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }
  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  Segment_app app_;
  string output_;
};

TEST_F(Segment_app_test, Do_Print_Help_Without_Arguments) {
  // Arrange
  vector<string> args = {};

  // Act
  Act(args);

  // Assert
  Assert("This is an intersecting segments application\\..*");
}

TEST_F(Segment_app_test, Is_Checking_Number_Of_Arguments) {
  // Arrange
  vector<string> args = { "1", "2" };

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Should be 8 arguments\\..*");
}

TEST_F(Segment_app_test, Can_Detect_Wrong_Number_Format) {
  // Arrange
  vector<string> args = { "1", "pi", "2", "4", "+", "3", "7", "5" };

  // Act
  Act(args);

  // Assert
  Assert("Wrong number format!.*");
}

TEST_F(Segment_app_test, Intersection_True) {
  // Arrange
  vector<string> args = { "1", "1", "1", "5", "0", "3", "2", "4" };

  // Act
  Act(args);

  // Assert
  Assert("Segments do intersect");
}

TEST_F(Segment_app_test, Intersection_False) {
  // Arrange
  vector<string> args = { "1", "1", "1", "5", "2", "3", "2", "4" };

  // Act
  Act(args);

  // Assert
  Assert("Segments do not intersect");
}
