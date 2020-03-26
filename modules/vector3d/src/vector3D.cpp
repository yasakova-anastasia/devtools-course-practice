// Copyright 2020 Sokolov Nikolai

#include <iostream>y
#include "include/vector3D.h"

Vector3D::Vector3D(const double& _x, const double& _y, const double& _z)
{
	X = _x;
	Y = _y;
	Z = _z;
}

double Vector3D::getX(){
	return X;
}

double Vector3D::getY(){
	return Y;
}

double Vector3D::getZ(){
	return Z;
}

void setX(double _x) {
	X = _x;
}

void setY(double _y) {
	Y = _y;
}

void setZ(double _z) {
	Z = _z;
}