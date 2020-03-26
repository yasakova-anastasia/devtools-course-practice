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

void Vector3D::normalization() {
	double summ = X + Y + Z;
	X /= summ; 
	Y /= summ;
	Z /= summ;
}

Vector3D normalization(const Vector3D& _v) {
	double summ = _v.->getX() + _v->getY() + _v->getZ();
	Vector3D normalization(_v->getX() / summ, _v->getY() / summ, _v->getZ() / summ);
	return normalization;
}

double ScalarProduct(const Vector3D& _v1, const Vector3D& _v2) {
	return _v1->getX() * _v2->getX() + _v1->getY() * _v2->getY() + _v1->getZ() * _v2->getZ();
}

Vector3D VectorProduct(const Vector3D& _v1, const Vector3D& _v2) {
	Vector3D reVectorProduct(_v1->getY() * _v2->getZ() - _v1->getZ() * _v2->getY(),
		                     _v1->getZ() * _v2->getX() - _v1->getX() * _v2->getZ(),
	                         _v1->getX() * _v2->getY() - _v1->getY() * _v2->getX());
	return  reVectorProduct;
}
