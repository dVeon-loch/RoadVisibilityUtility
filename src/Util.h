#pragma once

#include <string>
#include <memory>

#include "SightDistanceCalculator.h"

#include "Vector3.h"

/*
* This namespace serves as a general grouping of utility methods that
* have been used in various places throughout the project.
* While some of these methodscould have been grouped into more specific namespaces or classes,
* it was decided to keep them together to not clutter the project too much.
*/
namespace Util
{
	bool isNumber(std::string string);

	float GetDistance(Vector3 start, Vector3 end);

	Vector3 cross(Vector3 vec1, Vector3 vec2);

	double dot(Vector3 vec1, Vector3 vec2);

	std::string OpenChooseCsvFileDialog(const std::string& title);
	
	std::string OpenSaveResultsFileDialog();

	std::string OpenShaderFileDialog(const std::string& title);
	
	void SaveResultsToFile(std::shared_ptr<std::vector<SightDistanceFailure>> sightDistanceFailures);
}