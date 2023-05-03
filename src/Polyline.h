#pragma once

#include <vector>
#include "Vector3.h"
class Polyline
{
private:
	std::vector<Vector3> m_vertices;
	unsigned int m_currentIndex{ 0 };
	std::vector<float> m_distancesForIndices;

public:
	Polyline(std::vector<Vector3> verticies);

	Polyline(const Polyline& polyline);

	Vector3 operator[](unsigned int index);

	Vector3 at(unsigned int index);

	unsigned int size();

	void IncrementCurrentVertex();

	Vector3 GetCurrentVertex() const;

	float GetDistanceAtIndex(unsigned int index) const;

};

