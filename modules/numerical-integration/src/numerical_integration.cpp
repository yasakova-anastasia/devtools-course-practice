// Copyright 2020 Boganov Sergei

#include <cmath>

#include "include/numerical_integration.h"

double NumericalIntegration::Left_rectangle_method(unsigned int N)
{
    double h = (b - a) / (double)N;
    double I = 0.0;
    double x;

    for (unsigned int i = 0; i < N; i++)
    {
        x = a + i * h;
        I += f(x);
    }

	return I * h;
}

double NumericalIntegration::Right_rectangle_method(unsigned int N)
{
    double h = (b - a) / (double)N;
    double I = 0.0;
    double x;

    for (unsigned int i = 1; i <= N; i++)
    {
        x = a + i * h;
        I += f(x);
    }

	return I * h;
}

double NumericalIntegration::Middle_rectangle_method(unsigned int N)
{
    double h = (b - a) / (double)N;
    double I = 0.0;
    double x;

    for (unsigned int i = 0; i < N; i++)
    {
        x = a + (i + 0.5) * h;
        I += f(x);
    }

	return I * h;
}

double NumericalIntegration::Trapezoid_method(unsigned int N)
{
    double h = (b - a) / (double)N;
    double I = 0.0;
    double x;

    for (unsigned int i = 0; i < N; i++)
    {
        x = a + i * h;
        I += (f(x) + f(x + h)) / 2.0;
    }

	return I * h;
}

double NumericalIntegration::Simpsons_method(unsigned int N)
{
    double h = (b - a) / (double)N;
    double I = 0.0;
    double x;

    for (unsigned int i = 0; i < N; i += 2)
    {
        x = a + i * h;
        I += f(x - h) + 4.0 * f(x) + f(x + h);
    }

	return I * h / 3.0;
}

double NumericalIntegration::Gauss_method(unsigned int N)
{
    double h = (b - a) / (double)N;
    double I = 0.0;
    double x, t1, t2;

    for (unsigned int i = 0; i < N; i++)
    {
        x = a + i * h;
        t1 = (2.0 * x + h) / 2.0;
        t2 = h / (2.0 * sqrt(3.0));
        I += f(t1 - t2) + f(t1 + t2);
    }

	return I * h / 2.0;
}
