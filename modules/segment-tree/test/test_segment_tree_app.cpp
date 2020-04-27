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

TEST_F(SegmentTreeAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"3", "1", "2", "e", "1", "0", "2", "max"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(SegmentTreeAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"2", "1", "3", "1", "0", "1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_5_elements) {
    vector<string> args = {
        "5", "1", "2", "3", "4", "5", "1", "0", "2", "+"};

    Act(args);

    Assert("Answers on queries: 6");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_4_elements) {
    vector<string> args = {
        "4", "1", "2", "3", "4", "2", "2", "3", "0", "1", "+"};

    Act(args);

    Assert("Answers on queries: 7, 3");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_2_elements) {
    vector<string> args = {"2", "1", "2", "1", "-1", "1", "+"};

    Act(args);

    Assert("left or right interval cannot be negative");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_2_elements_2) {
    vector<string> args = {"2", "1", "2", "1", "1", "0", "+"};

    Act(args);

    Assert("left interval cannot be > than right");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_2_elements_3) {
    vector<string> args = {"2", "1", "2", "1", "1", "3", "+"};

    Act(args);

    Assert("right interval cannot be > that size");
}

/*TEST(SegmentTreeAppTest, Test_Range_Sum_Query_With_7_elements_and_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6, 7};

    // Act
    SegmentTree tree(test, "+");
    tree.update(3, -5);

    // Arrange
    EXPECT_EQ(tree.query(3, 4), 0);
}


TEST(SegmentTreeAppTest, Test_Range_Sum_Query_With_5_elements_and_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5};

    // Act
    SegmentTree tree(test, "+");
    tree.update(1, 0);

    // Arrange
    EXPECT_EQ(tree.query(0, 2), 4);
}

TEST(SegmentTreeAppTest, Test_Range_Sum_Query_With_6_elements_and_2_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6};

    // Act
    SegmentTree tree(test, "+");
    tree.update(1, 0);
    tree.update(1, -1);

    // Arrange
    EXPECT_EQ(tree.query(0, 2), 3);
}

TEST(SegmentTreeAppTest, Test_Range_Sum_Query_With_2_elements_update) {
    // Arrange
    std::vector <int> test = {1, 2};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_ANY_THROW(tree.update(-1, 1));
}

TEST(SegmentTreeAppTest, Test_Range_Sum_Query_With_3_elements_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_ANY_THROW(tree.update(3, 1));
}

TEST(SegmentTreeAppTest, Test_Range_Max_Query_With_5_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5};

    // Act
    SegmentTree tree(test, "max");

    // Arrange
    EXPECT_EQ(tree.query(0, 2), 3);
}


TEST(SegmentTreeAppTest, Test_Range_Min_Query_With_4_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4};

    // Act
    SegmentTree tree(test, "min");

    // Arrange
    EXPECT_EQ(tree.query(2, 3), 3);
}

TEST(SegmentTreeAppTest, Test_Range_Gcd_Query_With_6_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6};

    // Act
    SegmentTree tree(test, "gcd");

    // Arrange
    EXPECT_EQ(tree.query(2, 4), 1);
}

TEST(SegmentTreeAppTest, Test_Range_Maximum_Query_With_7_elements) {
    // Arrange
    std::vector <int> test = {2, 2, 3, 4, 8, 6, 12};

    // Act
    SegmentTree tree(test, "max");

    // Arrange
    EXPECT_EQ(tree.query(1, 5), 8);
}*/
