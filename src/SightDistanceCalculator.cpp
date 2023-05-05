#include "SightDistanceCalculator.h"
#include "IntersectionCalculator.h"
#include "Util.h"

#include <fstream>

SightDistanceCalculator::SightDistanceCalculator(std::shared_ptr<Polyline> polyline, std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles) : m_polyline(polyline), m_roadSurfaceTriangles(roadSurfaceTriangles), m_intersectionCalculator(roadSurfaceTriangles)
{
}

const std::shared_ptr<std::vector<SightDistanceFailure>> SightDistanceCalculator::GetSightDistanceFailures() const
{
	static auto sightDistanceFailures = CalculateSightDistanceFailures();

	return sightDistanceFailures;
}

const std::shared_ptr<std::vector<SightDistanceFailure>> SightDistanceCalculator::CalculateSightDistanceFailures() const
{
	auto sightDistanceFailures = std::make_shared<std::vector<SightDistanceFailure>>();
	for (unsigned int i = 0; i < m_polyline->size(); i++) {
		Vector3 currentViewPos = m_polyline -> at(i);
		SightDistanceFailure sightDistanceFailure(currentViewPos, m_polyline->GetDistanceAtIndex(i));
		float distance = 0;
		unsigned int indexOffset = 1;
		bool vertexFailed{ false };
		std::pair<float, float> visibilityRange(-1, -1);
		while (distance <= 350 && (i+indexOffset) < m_polyline->size())
		{
			Vector3 previousTargetPos = m_polyline->at(i+(indexOffset - 1));
			Vector3 targetPos = m_polyline->at(i+indexOffset);
			indexOffset++;
			
			// Since the distance between each consecutive polyline point might change, add each one
			distance += Util::GetDistance(previousTargetPos, targetPos);
			Intersection intersection = m_intersectionCalculator.GetIntersectsWithRoad(currentViewPos, targetPos);
			if (intersection.intersected)
			{
				vertexFailed = true;
				if (visibilityRange.first == -1.f) visibilityRange.first = distance;
				std::cout << std::fixed;
				sightDistanceFailure.AddIntersectionAndDistance(std::make_pair(intersection.intersectionCoord, distance));
			}
			else if (visibilityRange.first != -1.f)
			{
				visibilityRange.second = distance;
				sightDistanceFailure.AddImpairedVisibilityRange(visibilityRange);
				visibilityRange = std::make_pair(-1.f, -1.f);
			}
		}
		if (vertexFailed)
		{
			if (visibilityRange.first != -1.f && visibilityRange.second == -1.f)
			{
				visibilityRange.second = distance;
				sightDistanceFailure.AddImpairedVisibilityRange(visibilityRange);
			}
			sightDistanceFailures->push_back(sightDistanceFailure);
		}
	}
	return sightDistanceFailures;
}
