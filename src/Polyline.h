#pragma once

#include <vector>
#include "Vector3.h"

/*
* This class serves as a wrapper for a vector of vertices, with additional methods to make it easier to work with
* and abstract away certain details. The distance along the polyline is also calculated here.
*/
class Polyline
{
private:
	std::vector<Vector3> m_vertices;
	std::vector<float> m_distancesForIndices;

public:
	Polyline(std::vector<Vector3> verticies);

	Polyline(const Polyline& polyline);

	Vector3 operator[](unsigned int index);

	Vector3 at(unsigned int index);

	unsigned int size();

	float GetDistanceAtIndex(unsigned int index) const;

};

