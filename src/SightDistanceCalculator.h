#pragma once
#include <vector>
#include <memory>

#include "Polyline.h"
#include "Triangle.h"
#include "IntersectionCalculator.h"


class cSightDistanceFailure
{
private:
	Vector3 m_polylineViewVertex;
	int m_polylineTargetDistanceMetres;

public:
	//Want to add intersected triangle here for rendering purposes
	cSightDistanceFailure(Vector3 polylineViewVertex, int targetDistanceMetres) : m_polylineViewVertex(polylineViewVertex), m_polylineTargetDistanceMetres(targetDistanceMetres)
	{
	}

	const Vector3 GetVertex() const
	{
		return m_polylineViewVertex;
	}

	const int GetDistanceMetres() const
	{
		return m_polylineTargetDistanceMetres;
	}
};


class cSightDistanceCalculator
{
private:
	std::shared_ptr<Polyline> m_polyline;
	std::shared_ptr<std::vector<Triangle>> m_roadSurfaceTriangles;
	cIntersectionCalculator m_intersectionCalculator;
	std::shared_ptr<std::vector<cSightDistanceFailure>> m_sightDistanceFailures;

	static const unsigned int DISTANCE_STEP_METRES{ 5 };

	const std::shared_ptr<std::vector<cSightDistanceFailure>> CalculateSightDistanceFailures() const;

public:
	cSightDistanceCalculator(std::shared_ptr<Polyline> polyline, std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles);

	const std::shared_ptr<std::vector<cSightDistanceFailure>> GetSightDistanceFailures() const;


};


