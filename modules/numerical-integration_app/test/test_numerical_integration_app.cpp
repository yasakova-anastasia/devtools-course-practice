// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/numerical_integration_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NumberIntegrationTest : public ::testing::Test {
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
    NumericalIntegrationApp app_;
    string output_;
};

TEST_F(NumberIntegrationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a numerical integration application\\..*");
}

TEST_F(NumberIntegrationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2", "3"};

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Of_Iteration) {
    vector<string> args = {"1", "3", "-1", "2", "2"};

    Act(args);

    Assert("Incorrect <number_of_iteration>.*");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Of_Function) {
    vector<string> args = {"1", "3", "100", "4", "2"};

    Act(args);

    Assert("Incorrect <number_of_function>.*");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Of_Algorithm) {
    vector<string> args = {"1", "3", "100", "2", "7"};

    Act(args);

    Assert("Incorrect <number_of_algorithm>.*");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_1) {
    vector<string> args = {"1", "3", "=", "2", "7"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_2) {
    vector<string> args = {"pi", "3", "100", "2", "7"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_3) {
    vector<string> args = {"1", "left", "100", "2", "7"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_4) {
    vector<string> args = {"1", "3", "100", "first", "7"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_5) {
    vector<string> args = {"1", "3", "100", "1", "second"};

    Act(args);

    Assert("Wrong number format!");
}
