#pragma once

#include "Vector3.h"

/*
* This class is a simple data class for holding 3 vertices that represent a triangle.
* This could have been a struct, but encapsulation of the data was preferred.
*/
class Triangle
{
private:
	Vector3 m_A, m_B, m_C;
public:
	Triangle(Vector3 A, Vector3 B, Vector3 C);

	Triangle(const Triangle& other);

	~Triangle(){}

	const Vector3& GetA() const;

	const Vector3& GetB() const;

	const Vector3& GetC() const;

	Triangle& operator=(const Triangle& other);
};

