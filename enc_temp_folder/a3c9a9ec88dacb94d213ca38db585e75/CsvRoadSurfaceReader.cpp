#include "CsvRoadSurfaceReader.h"
#include "Util.h"


cCsvRoadSurfaceReader::cCsvRoadSurfaceReader(const char* filePath) : cRoadSurfaceReader(filePath)
{
}

const std::vector<Triangle> cRoadSurfaceReader::ReadRoadSurface()
{
	std::ifstream inputFile;
	inputFile.open(m_filePath);

	std::vector<Triangle> roadSurfaceTriangles;
	std::vector<int> test;
	roadSurfaceTriangles.reserve(3144);
	std::string line;

	while (std::getline(inputFile, line))
	{
		std::stringstream str(line);
		std::vector<Vertex> triangleVertices;
		triangleVertices.reserve(3);
		bool invalidTriangle{ false };
		for (auto i{ 0 }; i < 3; i ++)
		{
			std::array<double, 3> vertex{ 0 };
			std::string vertexComponent;
			for (auto j{ 0 }; j < 3; j++) {
				std::getline(str, vertexComponent, ',');
				if(!Util::isNumber(vertexComponent)) 
				{
					invalidTriangle = true;
					break;
				}
					vertex[j] = std::stod(vertexComponent);
			}
			if (invalidTriangle) 
			{
				break;
			}
				// Avoid unnecessary copies
				triangleVertices.emplace_back(Vertex{ vertex });
		}
		if(!invalidTriangle){
			roadSurfaceTriangles.emplace_back(Triangle{ triangleVertices[0], triangleVertices[1], triangleVertices[2] });
			//test.push_back(69);
		}
	}
	return roadSurfaceTriangles;
}