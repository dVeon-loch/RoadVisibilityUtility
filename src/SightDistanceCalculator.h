#pragma once
#include <vector>
#include <memory>
#include <utility>

#include "Polyline.h"
#include "Triangle.h"
#include "IntersectionCalculator.h"

/*
* This class forms the result set of each view vertex. It contains a number of data fields that can be used to record useful results.
*/
class SightDistanceFailure
{
private:
	Vector3 m_polylineViewVertex;
	float m_distanceFromStartMetres;
	std::vector<std::pair<Vector3, float>> m_intersectionsAndDistances;
	std::vector<std::pair<float, float>> m_impairedVisibilityRanges;
public:
	SightDistanceFailure(Vector3 polylineViewVertex, float distanceFromStartMetres) : m_polylineViewVertex(polylineViewVertex), m_distanceFromStartMetres(distanceFromStartMetres)
	{
	}

	void AddIntersectionAndDistance(std::pair<Vector3, float> intersectionAndDistance)
	{
		m_intersectionsAndDistances.push_back(intersectionAndDistance);
	}

	const std::vector<std::pair<Vector3, float>>& GetIntersectionsAndDistances() const
	{
		return m_intersectionsAndDistances;
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

/*
* This class contains the overall algorithm for the task of calculating the visibility
* of each vertex on the view polyline for distances up to 350m away.
*/
class SightDistanceCalculator
{
private:
	std::shared_ptr<Polyline> m_polyline;
	std::shared_ptr<std::vector<Triangle>> m_roadSurfaceTriangles;
	IntersectionCalculator m_intersectionCalculator;
	std::shared_ptr<std::vector<SightDistanceFailure>> m_sightDistanceFailures;


public:
	SightDistanceCalculator(std::shared_ptr<Polyline> polyline, std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles);

	/*
	* This method calculates the sight distance failures once and then caches it in a static local variable for use later if needed.
	*/
	const std::shared_ptr<std::vector<SightDistanceFailure>> GetSightDistanceFailures() const;

private:
	/*
	* This method performs the overall algorithm mentioned above.
	*/
	const std::shared_ptr<std::vector<SightDistanceFailure>> CalculateSightDistanceFailures() const;

};


