#include "CsvPolylineReader.h"
#include "CsvRoadSurfaceReader.h"
#include "SightDistanceCalculator.h"
#include "Util.h"

int main()
{
	cCsvPolylineReader polylineReader{ "C:\\personaldev\\CivilDesigner\\ProgrammingTask\\RoadVisibilityUtility\\data\\polyline.csv" };
	std::shared_ptr<Polyline> polyline = polylineReader.ReadPolyline();
	

	cCsvRoadSurfaceReader roadSurfaceReader{"C:\\personaldev\\CivilDesigner\\ProgrammingTask\\RoadVisibilityUtility\\data\\TIN Model Road Surface.csv"};
	auto roadSurfaceTriangles = roadSurfaceReader.ReadRoadSurface();

	cSightDistanceCalculator sightDistanceCalculator(polyline, roadSurfaceTriangles);

	auto sightDistanceFailures = sightDistanceCalculator.GetSightDistanceFailures();

	for (const auto& failure : *sightDistanceFailures)
	{
		Vector3 failureVertex = failure.GetVertex();
		int failureDistanceMetres = failure.GetDistanceMetres();
		std::cout << "At Vertex with co-ordinates: {" << failureVertex.x() << ", " << failureVertex.y() << ", " << failureVertex.z() << "}" << std::endl;
		std::cout << "Target Distance Failed: " << failureDistanceMetres << "m" << std::endl;
	}



	std::cin.get();
	return 0;
}