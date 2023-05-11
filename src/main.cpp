#include "RenderHandler.h"
#include "CsvPolylineReader.h"
#include "CsvRoadSurfaceReader.h"
#include "SightDistanceCalculator.h"
#include "Util.h"



int main()
{
	CsvPolylineReader polylineReader{ Util::OpenChooseCsvFileDialog("Select Polyline File") };
	std::shared_ptr<Polyline> polyline = polylineReader.ReadPolyline();


	CsvRoadSurfaceReader roadSurfaceReader{ Util::OpenChooseCsvFileDialog("Select Road Surface File") };
	std::shared_ptr<std::vector<Triangle>> roadSurfaceTriangles = roadSurfaceReader.ReadRoadSurface();

	SightDistanceCalculator sightDistanceCalculator(polyline, roadSurfaceTriangles);

	std::shared_ptr<std::vector<SightDistanceFailure>> sightDistanceFailures = sightDistanceCalculator.GetSightDistanceFailures();

	RenderHandler renderHandler(roadSurfaceTriangles, polyline, sightDistanceFailures);

	renderHandler.InitRenderLoop();

	Util::SaveResultsToFile(sightDistanceFailures);

	return 0;
}