#include "Polyline.h"
#include "Util.h"

#include <cmath>

Polyline::Polyline(std::vector<Vector3> verticies): m_vertices(verticies)
{
    for (unsigned int i = 0; i<m_vertices.size(); i++)
    {
        if (i == 0) m_distancesForIndices.push_back(0);
        else m_distancesForIndices.push_back(Util::GetDistance(m_vertices[i - 1], m_vertices[i]) + m_distancesForIndices[i-1]);
    }
}

Polyline::Polyline(const Polyline& polyline): m_vertices(polyline.m_vertices), m_currentIndex(polyline.m_currentIndex)
{
}

Vector3 Polyline::operator[](unsigned int index)
{
    return m_vertices[index];
}

Vector3 Polyline::at(unsigned int index)
{
    return m_vertices.at(index);
}

unsigned int Polyline::size()
{
    return m_vertices.size();
}

void Polyline::IncrementCurrentVertex()
{
    m_currentIndex++;
}

Vector3 Polyline::GetCurrentVertex() const
{
    return m_vertices[m_currentIndex];
}

float Polyline::GetDistanceAtIndex(unsigned int index) const
{
    return m_distancesForIndices[index];
}
