// Copyright 2020 Sokolov Nikolai

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_

class Vector3D {
public:
	explicit Vector3D(const double& _x = 0, const double& _y = 0, const double& _z = 0);
	Vector3D(const Vector3D& _v);
	double getX();
	double getY();
	double getZ();
	void setX(const double& _x);
	void setY(const double& _y);
	void setZ(const double& _z);
private:
	double X;
	double Y;
	double Z;
};

#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_