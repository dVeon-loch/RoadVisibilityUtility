#include <iostream>
#include "Vector3.h"
#include "Util.h"


//Vertex::Vertex(float x, float y, float z) : m_x{ x }, m_y{ y }, m_z{ z }
//{
//}

const Vector3 Vector3::ZERO = Vector3{ 0,0,0 };

Vector3::Vector3(double x, double y, double z) : m_x{ x }, m_y{ y }, m_z{ z }
{
}

Vector3::Vector3(std::array<float, 3> vertices) : Vector3(vertices[0], vertices[1], vertices[2])
{
}

Vector3::Vector3(std::array<double, 3> vertices) : Vector3(vertices[0], vertices[1], vertices[2])
{
}

 double Vector3::x()
{
	return m_x;
}
 double Vector3::y()
{
	return m_y;
}
 double Vector3::z()
{
	return m_z;
}
// std::array returns whole array so this does not get destroyed when scope ends.
const std::array<double, 3> Vector3::GetArray()
{
	return { m_x, m_y, m_z };
}

Vector3 Vector3::normalized() const
{
	return Vector3( *this / this->magnitude() );
}

double Vector3::magnitude() const
{
	return Util::GetDistance(ZERO, *this);
}

Vector3 Vector3::operator/(double denominator) const
{
	Vector3 numerator = *this;
	return Vector3{numerator.m_x / denominator, numerator.m_y / denominator, numerator.m_z / denominator };
}

Vector3 Vector3::operator+(Vector3 addend) const
{
	return Vector3{this->m_x + addend.m_x, this->m_y + addend.m_y, this->m_z + addend.m_z};
}

Vector3 Vector3::operator-(Vector3 subtrahend) const
{
	return Vector3{this->m_x - subtrahend.m_x, this->m_y - subtrahend.m_y, this->m_z - subtrahend.m_z};
}


Vector3 Vector3::operator*(double multiplicand) const
{
	return Vector3{ this->m_x * multiplicand, this->m_y * multiplicand, this->m_z * multiplicand };
}

std::ostream& operator<<(std::ostream& Str, const Vector3& v)
{
	return Str << "x: " << v.m_x << ", y: " << v.m_y << ", z:" << v.m_z;
}
