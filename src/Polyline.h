#pragma once

#include <vector>
#include "Vertex.h"
class Polyline
{
private:
	std::vector<Vertex> m_verticies;
	unsigned int m_currentIndex{ 0 };

public:
	Polyline(std::vector<Vertex> verticies);

	Polyline(const Polyline& polyline);
};

