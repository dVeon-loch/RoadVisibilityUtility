#pragma once

#include <string>

#include "Vector3.h"

namespace Util
{
	bool isNumber(std::string string);

	float GetDistance(Vector3 start, Vector3 end);

	Vector3 cross(Vector3 vec1, Vector3 vec2);

	double dot(Vector3 vec1, Vector3 vec2);
}