#pragma once
#include "Renderer.h"
#include <memory>
#include <vector>

#include "Triangle.h"
#include "Polyline.h"
#include "SightDistanceFailure.h"
#include "VertexArray.h"

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
	RenderHandler(std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles, std::shared_ptr<Polyline> polyline, std::shared_ptr<std::vector<SightDistanceFailure>> sightDistanceFailures);
	~RenderHandler();

	void DrawRoadSurface(Color color = {0.f,1.f,0.f});
	void DrawPolyline(Color color = { 0.f,0.f,1.f });
	void DrawResults(Color roadColor = { 0.f,1.f,0.f }, Color polylineColor = { 0.f,0.f,1.f }, Color viewLineColor = { 1.f,1.f,0.f }, Color failedTriangleColor = { 1.f,0.65f,0.f }, Color polylineFailedColor = { 1.f,0,0 });
	int InitRenderLoop();
private:
	std::shared_ptr<VertexArray> TrianglesToVertexArray();
	std::shared_ptr<VertexArray> PolylineToVertexArray();
	std::shared_ptr<VertexArray> ResultsToVertexArray();
};

