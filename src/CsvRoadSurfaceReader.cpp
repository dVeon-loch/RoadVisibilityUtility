#include "CsvRoadSurfaceReader.h"
#include "Util.h"


CsvRoadSurfaceReader::CsvRoadSurfaceReader(const std::string& filePath) : RoadSurfaceReader(filePath)
{
}

const std::shared_ptr<std::vector<Triangle>> RoadSurfaceReader::ReadRoadSurface()
{
	std::ifstream inputFile;
	inputFile.open(m_filePath);

	std::vector<Triangle> roadSurfaceTriangles;
	std::vector<int> test;
	//TODO make function in utility namespace to get lines of a file
	roadSurfaceTriangles.reserve(3144);
	std::string line;

	while (std::getline(inputFile, line))
	{
		std::stringstream str(line);
		std::vector<Vector3> triangleVertices;
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
				triangleVertices.emplace_back(Vector3{ vertex });
		}
		if(!invalidTriangle){
			roadSurfaceTriangles.emplace_back(Triangle{ triangleVertices[0], triangleVertices[1], triangleVertices[2] });
		}
	}
	return std::make_shared<std::vector<Triangle>>(roadSurfaceTriangles);
}