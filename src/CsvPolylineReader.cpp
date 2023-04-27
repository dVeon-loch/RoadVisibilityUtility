#include "CsvPolylineReader.h"

cCsvPolylineReader::cCsvPolylineReader(const char* filePath) : cPolylineReader(filePath)
{
}

Polyline cPolylineReader::ReadPolyline()
{
	std::ifstream inputFile;
	inputFile.open(m_filePath);

	std::vector<Vertex> polyline;
	polyline.reserve(114);
	std::string line;

	while (std::getline(inputFile, line))
	{
		if (line == "") 
		{
			continue;
		}
			std::stringstream str(line);
			std::array<double, 3> vertexComponents;
			std::string vertexComponent;
			for (auto i{ 0 }; i < 3; i++) {
				std::getline(str, vertexComponent, ',');
				vertexComponents[i] = std::stod(vertexComponent);
			}
			polyline.emplace_back(Vertex {vertexComponents});
	}
	return Polyline{ polyline };
}