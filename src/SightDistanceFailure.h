#pragma once

#include <vector>
#include <utility>

#include "Vector3.h"

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

	const std::vector<std::pair<float, float>>& GetImpairedVisibilityRanges() const
	{
		return m_impairedVisibilityRanges;
	}

	float GetDistanceFromStartMetres() const
	{
		return m_distanceFromStartMetres;
	}
};