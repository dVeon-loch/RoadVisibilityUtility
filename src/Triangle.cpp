#include "Triangle.h"

#include <iostream>

Triangle::Triangle(Vertex A, Vertex B, Vertex C) : m_A(A), m_B(B), m_C(C)
{
}

Triangle::Triangle(const Triangle& other) : m_A(other.m_A), m_B(other.m_B), m_C(other.m_C)
{
	std::cout << "Copy constructor called!" << std::endl;
}

const Vertex Triangle::GetA()
{
	return m_A;
}

const Vertex Triangle::GetB()
{
	return m_B;
}

const Vertex Triangle::GetC()
{
	return m_C;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        m_A = other.m_A;
        m_B = other.m_B;
        m_C = other.m_C;
    }
    return *this;
}
