// Copyright 2020 SAVIN DMITRIY
#ifndef MODULES_SALARY_INCLUDE_SALARY_H_
#define MODULES_SALARY_INCLUDE_SALARY_H_
class Salary {
 public:
    Salary();
    ~Salary();
    float payment();
    void setSalary(float s);
    void setHours(int h);
    void setOverHours(int h);
    void setAdminHours(int h);
 private:
    float m_salary;
    int m_hours;
    int m_hours_over;
    int m_hours_admin;
};
#endif  // MODULES_SALARY_INCLUDE_SALARY_H_
