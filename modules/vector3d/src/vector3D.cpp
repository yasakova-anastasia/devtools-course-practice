// Copyright 2020 Sokolov Nikolai

#include <iostream>
#include "include/vector3D.h"

Vector3D::Vector3D(const double& _x, const double& _y, const double& _z) : X(_x), Y(_y), Z(_z)
{
}

Vector3D::Vector3D(const Vector3D& _v)
{
	X = _v.X;
	Y = _v.Y;	
	Z = _v.Z;
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

void Vector3D::setX(const double& _x) {
	X = _x;
}

void Vector3D::setY(const double& _y) {
	Y = _y;
}

void Vector3D::setZ(const double& _z) {
	Z = _z;
}