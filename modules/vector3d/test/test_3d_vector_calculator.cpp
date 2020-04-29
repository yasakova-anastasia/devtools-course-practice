// Copyright 2020 Baldin Alexey

#include <gtest/gtest.h>

#include <string>

#include "include/vector3D.h"
#include "include/vector3D_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Vector3DCalculatorTest : public ::testing::Test {
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
    Vector3DCalculator app_;
    string output_;
};

TEST_F(Vector3DCalculatorTest, Can_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a 3d vector calculator application\\..*");
}

TEST_F(Vector3DCalculatorTest, Check_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("Should be 7 arguments\\..*");
}
