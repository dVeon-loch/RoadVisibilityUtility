#pragma once
#include <vector>
#include <memory>
#include <utility>

#include "Polyline.h"
#include "Triangle.h"
#include "IntersectionCalculator.h"
#include "SightDistanceFailure.h"



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


