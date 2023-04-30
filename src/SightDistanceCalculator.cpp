#include "SightDistanceCalculator.h"
#include "IntersectionCalculator.h"

cSightDistanceCalculator::cSightDistanceCalculator(std::shared_ptr<Polyline> polyline, std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles) : m_polyline(polyline), m_roadSurfaceTriangles(roadSurfaceTriangles), m_intersectionCalculator(roadSurfaceTriangles)
{
}

const std::shared_ptr<std::vector<cSightDistanceFailure>> cSightDistanceCalculator::GetSightDistanceFailures() const
{
	static auto sightDistanceFailures = CalculateSightDistanceFailures();

	return sightDistanceFailures;
}

const std::shared_ptr<std::vector<cSightDistanceFailure>> cSightDistanceCalculator::CalculateSightDistanceFailures() const
{
	auto sightDistanceFailures = std::make_shared<std::vector<cSightDistanceFailure>>();
	for (int i = 0; i < m_polyline->size(); i++) {
		Vector3 currentViewPos = m_polyline->GetAndIncrement();
		for (int distance = 0; distance < 350; distance += DISTANCE_STEP_METRES)
		{
			if (m_intersectionCalculator.GetIntersectsWithRoad(currentViewPos, m_polyline->GetVertexAtDistanceMetres(distance)))
			{
				sightDistanceFailures->emplace_back(cSightDistanceFailure{ currentViewPos, distance });
			}
		}
	}
	return sightDistanceFailures;
}
