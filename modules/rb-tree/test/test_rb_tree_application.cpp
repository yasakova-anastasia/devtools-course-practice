// Copyright 2020 Isaev Ilya

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "include/rb_tree_application.h"

using ::testing::internal::RE;

class RBTreeAppTest: public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("RBTreeApplication");
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
    std::string output_;
    RBTreeApp app_;
};

TEST_F(RBTreeAppTest, Print_Help_If_No_Args_Given) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a Red-black tree application\\..*");
}