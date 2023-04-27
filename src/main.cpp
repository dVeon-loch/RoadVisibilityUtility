#include "CsvPolylineReader.h"
#include "CsvRoadSurfaceReader.h"

int main()
{
	cCsvPolylineReader polylineReader{ "C:\\personaldev\\CivilDesigner\\ProgrammingTask\\RoadVisibilityUtility\\data\\polyline.csv" };
	auto polyline = polylineReader.ReadPolyline();
	

	cCsvRoadSurfaceReader roadSurfaceReader{"C:\\personaldev\\CivilDesigner\\ProgrammingTask\\RoadVisibilityUtility\\data\\TIN Model Road Surface.csv"};
	auto roadSurfaceTriangles = roadSurfaceReader.ReadRoadSurface();


	std::cin.get();
	return 0;
}