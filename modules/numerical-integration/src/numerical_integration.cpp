// Copyright 2020 Boganov Sergei

#include <cmath>
#include <string>

#include "include/numerical_integration.h"

NumericalIntegration::NumericalIntegration(
    double _a, double _b, double (*_f)(double x)) {
    if (_a >= _b) {
        throw static_cast<std::string>(
            "The left border should be less than the right border");
    }

    a = _a;
    b = _b;
    f = _f;
}

NumericalIntegration::NumericalIntegration(
    const NumericalIntegration& obj) : a(obj.a), b(obj.b), f(obj.f) {
}

NumericalIntegration& NumericalIntegration::operator=(
    const NumericalIntegration& obj) {
    a = obj.a;
    b = obj.b;
    f = obj.f;

    return *this;
}

bool NumericalIntegration::operator == (
    const NumericalIntegration& obj) const {
    return ((a == obj.a) && (b == obj.b) && (f == obj.f));
}

double NumericalIntegration::Left_rectangle_method(unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        I += f(x);
    }

    return I * h;
}

double NumericalIntegration::Right_rectangle_method(unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 1; i <= N; i++) {
        double x = a + i * h;
        I += f(x);
    }

    return I * h;
}

double NumericalIntegration::Middle_rectangle_method(unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        I += f(x);
    }

    return I * h;
}

double NumericalIntegration::Trapezoid_method(unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        I += (f(x) + f(x + h)) / 2.0;
    }

    return I * h;
}

double NumericalIntegration::Simpsons_method(unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i += 2) {
        double x = a + i * h;
        I += f(x - h) + 4.0 * f(x) + f(x + h);
    }

    return I * h / 3.0;
}

double NumericalIntegration::Gauss_method(unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        double t1 = (2.0 * x + h) / 2.0;
        double t2 = h / (2.0 * sqrt(3.0));
        I += f(t1 - t2) + f(t1 + t2);
    }

    return I * h / 2.0;
}
