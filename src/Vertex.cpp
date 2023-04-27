#include "Vertex.h"

#include <iostream>


Vertex::Vertex(float x, float y, float z) : m_x{ x }, m_y{ y }, m_z{ z }
{
}

Vertex::Vertex(double x, double y, double z) : m_x{ x }, m_y{ y }, m_z{ z }
{
}

Vertex::Vertex(std::array<float, 3> vertices) : Vertex(vertices[0], vertices[1], vertices[2])
{
}

Vertex::Vertex(std::array<double, 3> vertices) : Vertex(vertices[0], vertices[1], vertices[2])
{
	std::cout << "Constructor called!" << std::endl;
}

 double Vertex::x()
{
	return m_x;
}
 double Vertex::y()
{
	return m_y;
}
 double Vertex::z()
{
	return m_z;
}
// std::array returns whole array so this does not get destroyed when scope ends.
const std::array<double, 3> Vertex::GetArray()
{
	return { m_x, m_y, m_z };
	// C++ 11 syntax
}