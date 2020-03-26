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

Vector3D& Vector3D::operator=(const Vector3D & v){
	if (this != &v)
	{
		X = v.X;
		Y = v.Y;
		Z = v.Z;
	}
	return *this;

}

Vector3D Vector3D::operator+(const Vector3D& _v) {
	Vector3D rez(this->X + _v.X, this->Y + _v.Y, this->Z + _v.Z);
	return rez;
}

Vector3D Vector3D::operator-(const Vector3D& _v) {
	Vector3D rez(this->X - _v.X, this->Y - _v.Y, this->Z - _v.Z);
	return rez;
}

double Vector3D::norm() {
	return sqrt ( X * X + Y * Y + Z * Z);
}
