// Copyright 2020 SAVIN DMITRIY 

#include <gtest/gtest.h>
#include "include/Salary.h"


class SalaryTest1 : public ::testing::Test
{

};

TEST_F(SalaryTest1, Work_Without_Administrative_Leave_And_Without_Hours_Worked)
{
    float m_salary = 120000;
    float m_hours = 40;
    float m_hours_over = 0;
    float m_hours_admin = 0;
    Salary a1;
    a1.setSalary(120000);
    a1.setHours(40);
    a1.setOverHours(0);
    a1.setAdminHours(0);
    float payment = a1.payment();

    EXPECT_EQ(payment, 120000);
}
TEST_F(SalaryTest1, Work_Without_Administrative_Leave_With_Two_Recycled_Hours)
{
    float m_salary = 120000;
    float m_hours = 40;
    float m_hours_over = 2;
    float m_hours_admin = 0;
    Salary a2;
    a2.setSalary(120000);
    a2.setHours(40);
    a2.setOverHours(2);
    a2.setAdminHours(0);
    float payment = a2.payment();
    EXPECT_EQ(payment, 129000);
}
TEST_F(SalaryTest1, Work_With_Administrative_Leave_With_Recycled_Watches)
{
    float m_salary = 120000;
    float m_hours = 40;
    float m_hours_over = 3;
    float m_hours_admin = 6;
    Salary a3;
    a3.setSalary(120000);
    a3.setHours(40);
    a3.setOverHours(3);
    a3.setAdminHours(6);
    float payment = a3.payment();
    EXPECT_EQ(payment, 111000);
}
TEST_F(SalaryTest1, Work_With_Administrative_Leave_Without_Hours)
{
    float m_salary = 120000;
    float m_hours = 40;
    float m_hours_over = 0;
    float m_hours_admin = 17;
    Salary a4;
    a4.setSalary(120000);
    a4.setHours(40);
    a4.setOverHours(0);
    a4.setAdminHours(17);
    float payment = a4.payment();
    EXPECT_EQ(payment, 69000);
}
TEST_F(SalaryTest1, Working_With_Zero_Hours_Worked)
{
    float m_salary = 120000;
    float m_hours = 0;
    float m_hours_over = 19;
    float m_hours_admin = 17;
    Salary a5;
    a5.setSalary(120000);
    a5.setHours(0);
    a5.setOverHours(19);
    a5.setAdminHours(17);
    float payment = a5.payment();
    float exptcted = 0.0;
    EXPECT_EQ(payment, exptcted);
}
TEST_F(SalaryTest1, Erroneous_Salary_Payment)
{
    float m_salary = -120000;
    float m_hours = 0;
    float m_hours_over = 19;
    float m_hours_admin = 17;
    Salary a6;
    a6.setSalary(-120000);
    a6.setHours(0);
    a6.setOverHours(19);
    a6.setAdminHours(17);
    float payment = a6.payment();
    float exptcted = 0.0;
    EXPECT_EQ(payment, exptcted);
}
