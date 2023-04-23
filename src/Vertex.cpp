#include "Vertex.h"


Vertex::Vertex(float x, float y, float z) : m_x{ x }, m_y{ y }, m_z{ z }
{
}

 float Vertex::x()
{
	return m_x;
}
float Vertex::y()
{
	return m_y;
}
float Vertex::z()
{
	return m_z;
}
// std::array returns whole array so this does not get destroyed when scope ends.
const std::array<float, 3> Vertex::GetArray()
{
	return { m_x, m_y, m_z };
	// C++ 11 syntax
}