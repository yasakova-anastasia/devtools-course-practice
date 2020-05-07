// Copyright 2020 Isaev Ilya

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "include/rb_tree_application.h"

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
 private:
    std::string output_;
    RBTreeApp app_;
}

TEST(RBTreeAppTest, fictive) {
    ASSERT_TRUE(true);
}