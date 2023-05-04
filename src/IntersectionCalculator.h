#pragma once

#include<memory>
#include<vector>

#include "Triangle.h"
#include "Vector3.h"

struct Intersection
{
	bool intersected{ false };
	Vector3 intersectionCoord;
};

class IntersectionCalculator
{
private:
	std::shared_ptr<std::vector<Triangle>> m_pRoadSurfaceTriangles;

	static const float EPSILON;

public:
	IntersectionCalculator(std::shared_ptr<std::vector<Triangle>> pRoadSurfaceTriangles);

	Intersection GetIntersectsWithRoad(const Vector3& startingVertex, const Vector3& targetVertex) const;
};

