// Copyright 2020 Boganov Sergei

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