#include "CsvRoadSurfaceReader.h"



cCsvRoadSurfaceReader::cCsvRoadSurfaceReader(const char* filePath) : cRoadSurfaceReader(filePath)
{
}

const std::vector<Vertex>& cRoadSurfaceReader::ReadRoadSurface()
{
	std::ifstream inputFile;
	inputFile.open(m_filePath, )
}