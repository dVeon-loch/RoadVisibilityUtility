#include "Polyline.h"

Polyline::Polyline(std::vector<Vertex> verticies): m_verticies(verticies)
{
}

Polyline::Polyline(const Polyline& polyline): m_verticies(polyline.m_verticies), m_currentIndex(polyline.m_currentIndex)
{
}
