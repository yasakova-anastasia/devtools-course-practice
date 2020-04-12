#include "include/converter.h"
#include <iostream>

double Convert::convert_to_Kelvins(const double& celsius)
{
	//double K = static_cast<double>(coeff_to_Kelvins + celsius);
	return (num_to_Kelvins + celsius);
}

double Convert::convert_to_Fahrenheit(const double& celsius)
{
	//double F = static_cast<double>(celsius * 1.8 + 32);
	return (celsius * 1.8 + 32);
}


double Convert::convert_to_Newton(const double& celsius)
{
	//double N = static_cast<double>(coeff_to_Newton * celsius);
	return (num_to_Newton * celsius);
}

