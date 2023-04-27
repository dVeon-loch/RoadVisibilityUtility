#pragma once

#include <array>
#include <iostream>
class Vertex
{
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Vertex(float x, float y, float z);

	Vertex(double x, double y, double z);

	Vertex(std::array<float, 3> vertices);

	Vertex(std::array<double, 3> vertices);

	Vertex() :m_x(0), m_y(0), m_z(0)
	{
	}

	~Vertex() 
	{
		std::cout << "Destructor called!" << std::endl;
	}

	double x();

	double y();

	double z();

	// std::array returns whole array so this does not get destroyed when scope ends.
	const std::array<double, 3> GetArray();

};

