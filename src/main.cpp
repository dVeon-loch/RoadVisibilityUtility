#include "CsvPolylineReader.h"
#include "CsvRoadSurfaceReader.h"
#include "SightDistanceCalculator.h"
#include "Util.h"

int main()
{
	CsvPolylineReader polylineReader{ "C:\\personaldev\\CivilDesigner\\ProgrammingTask\\RoadVisibilityUtility\\data\\polyline.csv" };
	std::shared_ptr<Polyline> polyline = polylineReader.ReadPolyline();
	

	CsvRoadSurfaceReader roadSurfaceReader{"C:\\personaldev\\CivilDesigner\\ProgrammingTask\\RoadVisibilityUtility\\data\\TIN Model Road Surface.csv"};
	auto roadSurfaceTriangles = roadSurfaceReader.ReadRoadSurface();

	cSightDistanceCalculator sightDistanceCalculator(polyline, roadSurfaceTriangles);

	auto sightDistanceFailures = sightDistanceCalculator.GetSightDistanceFailures();

	std::ofstream file("VisibilityRanges.txt");
	file << std::fixed;
	file.clear();
	if (file.is_open())
	{

		for (const auto& failure : *sightDistanceFailures)
		{
			Vector3 failureVertex = failure.GetVertex();
			file << "At Vertex " << failure.GetDistanceFromStartMetres() << " metres from the start, visibility is impaired in the following distance ranges: " << std::endl;
			for (const auto& range : failure.GetImpairedVisibilityRanges())
			{
				file << range.first << "m to " << range.second << "m" << std::endl;
			}
		}
	}
	file.flush();
	file.close();
	return 0;
}