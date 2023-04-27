#pragma once

#include "Vertex.h"

class Triangle
{
private:
	Vertex m_A, m_B, m_C;
public:
	Triangle(Vertex A, Vertex B, Vertex C);

	Triangle(const Triangle& other);

	~Triangle(){}

	const Vertex GetA();

	const Vertex GetB();

	const Vertex GetC();

	Triangle& operator=(const Triangle& other);
};

