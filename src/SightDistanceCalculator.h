#pragma once
#include <vector>
#include <memory>
#include <utility>

#include "Polyline.h"
#include "Triangle.h"
#include "IntersectionCalculator.h"


class cSightDistanceFailure
{
private:
	Vector3 m_polylineViewVertex;
	float m_distanceFromStartMetres;
	std::vector<std::pair<float, float>> m_impairedVisibilityRanges;
public:
	//Want to add intersected triangle here for rendering purposes
	cSightDistanceFailure(Vector3 polylineViewVertex, float distanceFromStartMetres) : m_polylineViewVertex(polylineViewVertex), m_distanceFromStartMetres(distanceFromStartMetres)
	{
	}

	void AddImpairedVisibilityRange(std::pair<float, float> impairedVisibilityRange)
	{
		m_impairedVisibilityRanges.push_back(impairedVisibilityRange);
	}

	const Vector3& GetVertex() const
	{
		return m_polylineViewVertex;
	}

	const std::vector<std::pair<float,float>>& GetImpairedVisibilityRanges() const
	{
		return m_impairedVisibilityRanges;
	}

	float GetDistanceFromStartMetres() const
	{
		return m_distanceFromStartMetres;
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


