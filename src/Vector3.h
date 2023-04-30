#pragma once

#include <array>
#include <iostream>
class Vector3
{
private:
	double m_x;
	double m_y;
	double m_z;
public:
	//Vertex(float x, float y, float z);

	static const Vector3 ZERO;

	Vector3(double x, double y, double z);

	Vector3(std::array<float, 3> vertices);

	Vector3(std::array<double, 3> vertices);

	Vector3() :m_x(0), m_y(0), m_z(0)
	{
	}

	~Vector3() 
	{
	}

	double x();

	double y();

	double z();

	// std::array returns whole array so this does not get destroyed when scope ends.
	const std::array<double, 3> GetArray();

	Vector3 normalized() const;
	double magnitude() const;

	Vector3 operator +(Vector3 addend) const;
	
	Vector3 operator -(Vector3 subtrahend) const;

	Vector3 operator *(double multiplicand) const;
	
	Vector3 operator /(double denominator) const;
};

