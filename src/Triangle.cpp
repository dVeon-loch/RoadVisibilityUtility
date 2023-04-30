#include "Triangle.h"

#include <iostream>

Triangle::Triangle(Vector3 A, Vector3 B, Vector3 C) : m_A(A), m_B(B), m_C(C)
{
}

Triangle::Triangle(const Triangle& other) : m_A(other.m_A), m_B(other.m_B), m_C(other.m_C)
{
}

const Vector3& Triangle::GetA() const
{
	return m_A;
}

const Vector3& Triangle::GetB() const
{
	return m_B;
}

const Vector3& Triangle::GetC() const
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
