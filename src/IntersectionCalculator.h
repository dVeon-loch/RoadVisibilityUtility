#pragma once

#include<memory>
#include<vector>

#include "Triangle.h"
#include "Vector3.h"

/*
Simple struct that will always be returned. If intersected == false the value will be ignored.
*/
struct Intersection
{
	bool intersected{ false };
	Vector3 intersectionCoord;
};

/*
* This class is only meant to perform the task of checking intersections between a ray defined by a start and end Vector3,
* and all triangles in the road surface. It is open to being extended, possibly for more efficient implementations.
*/
class IntersectionCalculator
{
private:
	std::shared_ptr<std::vector<Triangle>> m_roadSurfaceTriangles;

	/*
	* Used for float comparison to zero
	*/
	static const float EPSILON;

public:
	IntersectionCalculator(std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles);

	/*
	* Gets an intersection of the current ray defined by a start and end, and the road surface. If the Intersection.intersected = true, then this ray intersected and the intersection coordinate can be used.
	*/
	Intersection GetIntersectsWithRoad(const Vector3& startingVertex, const Vector3& targetVertex) const;
};

