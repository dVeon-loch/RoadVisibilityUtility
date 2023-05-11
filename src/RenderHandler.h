#pragma once

#include <memory>
#include <vector>

#include "Triangle.h"
#include "Polyline.h"
#include "SightDistanceFailure.h"

struct Color
{
	float r, g, b;
};

class RenderHandler
{
private:
	std::shared_ptr<std::vector<Triangle>> m_roadSurfaceTriangles;
	std::shared_ptr<Polyline> m_Polyline;
	std::shared_ptr<std::vector<SightDistanceFailure>> m_SightDistanceFailures;
public:
	void DrawRoadSurface(Color color);
	void DrawPolyline(Color color);
	void DrawResults(Color roadColor = { 0.f,1.f,0.f }, Color polylineColor = { 0.f,0.f,1.f }, Color viewLineColor = { 1.f,1.f,0.f }, Color failedTriangleColor = { 1.f,0.65f,0.f }, Color polylineFailedColor = { 1.f,0,0 });
	int InitRenderLoop();
};

