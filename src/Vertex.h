#pragma once

#include <array>
class Vertex
{
private:
	float m_x;
	float m_y;
	float m_z;
public:
	Vertex(float x, float y, float z);

	float x();

	float y();

	float z();

	// std::array returns whole array so this does not get destroyed when scope ends.
	const std::array<float, 3> GetArray()
}
};

