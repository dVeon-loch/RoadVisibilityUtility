#include "RenderHandler.h"

/*
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
*/



RenderHandler::RenderHandler(std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles, std::shared_ptr<Polyline> polyline, std::shared_ptr<std::vector<SightDistanceFailure>> sightDistanceFailures) : m_roadSurfaceTriangles(roadSurfaceTriangles), m_Polyline(polyline), m_SightDistanceFailures(sightDistanceFailures)
{
}

RenderHandler::~RenderHandler()
{
}

void RenderHandler::DrawRoadSurface(Color color)
{
}

void RenderHandler::DrawPolyline(Color color)
{
}

void RenderHandler::DrawResults(Color roadColor, Color polylineColor, Color viewLineColor, Color failedTriangleColor, Color polylineFailedColor)
{
}

int RenderHandler::InitRenderLoop()
{
	return -1;
}

std::shared_ptr<VertexArray> RenderHandler::TrianglesToVertexArray()
{
	return std::shared_ptr<VertexArray>();
}

std::shared_ptr<VertexArray> RenderHandler::PolylineToVertexArray()
{
	return std::shared_ptr<VertexArray>();
}

std::shared_ptr<VertexArray> RenderHandler::ResultsToVertexArray()
{
	return std::shared_ptr<VertexArray>();
}


