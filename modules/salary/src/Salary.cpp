// Copyright 2020 SAVIN DMITRIY
#include "include/Salary.h"

Salary::Salary() {
}


Salary::~Salary() {
}

float Salary::payment() {
    if (m_hours <= 0) {
    return 0.0f;
    }
    float paymentPerHour = m_salary / m_hours;
    float payment = (m_hours - m_hours_admin) * paymentPerHour;
    float paymentOver;
    if (m_hours_over <= 2) {
    paymentOver = paymentPerHour * 1.5f * m_hours_over;
    } else {
        paymentOver = paymentPerHour * 2.f * (m_hours_over - 2) +
            paymentPerHour * 1.5f * 2;
    }
    payment += paymentOver;
    return payment;
}

void Salary::setSalary(float s) {
    m_salary = s;
}

void Salary::setHours(int h) {
    m_hours = h;
}

void Salary::setOverHours(int h) {
    m_hours_over = h;
}

void Salary::setAdminHours(int h) {
    m_hours_admin = h;
}
