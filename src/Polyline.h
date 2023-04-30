#pragma once

#include <vector>
#include "Vector3.h"
class Polyline
{
private:
	std::vector<Vector3> m_vertices;
	unsigned int m_currentIndex{ 0 };

	float GetDistanceBetweenVerticesMetres();

public:
	Polyline(std::vector<Vector3> verticies);

	Polyline(const Polyline& polyline);

	Vector3 operator[](unsigned int index);

	unsigned int size();

	Vector3 GetVertexAtDistanceMetres(float distanceMetres);

	Vector3 GetAndIncrement();

};

