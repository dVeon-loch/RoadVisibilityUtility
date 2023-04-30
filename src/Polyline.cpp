#include "Polyline.h"
#include "Util.h"

#include <cmath>

float Polyline::GetDistanceBetweenVerticesMetres()
{
    // Only calculate this once
    static float distanceMetres{ Util::GetDistance(m_vertices[0], m_vertices[1]) };
    return distanceMetres;
}

Polyline::Polyline(std::vector<Vector3> verticies): m_vertices(verticies)
{
}

Polyline::Polyline(const Polyline& polyline): m_vertices(polyline.m_vertices), m_currentIndex(polyline.m_currentIndex)
{
}

Vector3 Polyline::operator[](unsigned int index)
{
    return m_vertices[index];
}

unsigned int Polyline::size()
{
    return m_vertices.size();
}

Vector3 Polyline::GetVertexAtDistanceMetres(float distanceMetres)
{
    unsigned int indexForTarget = m_currentIndex + std::ceil(distanceMetres / GetDistanceBetweenVerticesMetres());
    if (indexForTarget < m_vertices.size()) {
        return m_vertices[indexForTarget];
    }
    else
    {
        return m_vertices.back();
    }
}

Vector3 Polyline::GetAndIncrement()
{
    return m_vertices[m_currentIndex++];
}
