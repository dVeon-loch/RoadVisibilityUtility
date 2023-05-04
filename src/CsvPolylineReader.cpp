#include "CsvPolylineReader.h"

CsvPolylineReader::CsvPolylineReader(const std::string& filePath) : cPolylineReader(filePath)
{
}

std::shared_ptr<Polyline> cPolylineReader::ReadPolyline()
{
	std::ifstream inputFile;
	inputFile.open(m_filePath);

	std::vector<Vector3> polyline;
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
			polyline.emplace_back(Vector3 {vertexComponents});
	}
	return std::make_shared<Polyline>(polyline);
}