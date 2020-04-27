// Copyright 2020 Boganov Sergei

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/segment_tree_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SegmentTreeAppTest : public ::testing::Test {
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
    SegmentTreeApp app_;
    string output_;
};

TEST_F(SegmentTreeAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a segment tree application\\..*");
}

TEST_F(SegmentTreeAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("Oops, incorrect number of parameters\\..*");
}

/*TEST_F(SegmentTreeAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"3", "1", "2", "e", "1", "0", "2", "max"};

    Act(args);

    Assert("Wrong number format!");
}*/

/*TEST_F(SegmentTreeAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"2", "1", "3", "1", "0", "1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(SegmentTreeAppTest, Can_Add_Complexs) {
    vector<string> args = {"2.0", "3.5", "1.5", "4.0", "+"};

    Act(args);

    Assert("Real = 3.5 Imaginary = 7.5");
}

TEST_F(SegmentTreeAppTest, Can_Diff_Complexs) {
    vector<string> args = {"13", "7.6", "26", "-14", "-"};

    Act(args);

    Assert("Real = -13 Imaginary = 21.6");
}

TEST_F(SegmentTreeAppTest, Can_Mult_Complexs) {
    vector<string> args = {"0", "-3.6", "17.4", "21", "*"};

    Act(args);

    Assert("Real = 75.6 Imaginary = -62.64");
}

TEST_F(SegmentTreeAppTest, Can_Divide_Complexs) {
    vector<string> args = {"27", "30", "15", "20", "/"};

    Act(args);

    Assert("Real = 1.608 Imaginary = -0.144");
}

TEST_F(SegmentTreeAppTest, Can_Detect_Divide_By_Zero) {
    vector<string> args = {"27", "30", "0", "0", "/"};

    Act(args);

    Assert("Can't divide by zero");
}*/
