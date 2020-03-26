// Copyright 2020 Sokolov Nikolai

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_

class Vector3D {
public:
	explicit Vector3D(const double& _x = 0, const double& _y = 0, const double& _z = 0);
	double getX();
	double getY();
	double getZ();
	void setX(double _x);
	void setY(double _y);
	void setZ(double _z);
private:
	double X;
	double Y;
	double Z;
};

#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_