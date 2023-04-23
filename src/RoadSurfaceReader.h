#pragma once

#include <vector>
#include<iostream>
#include <fstream>

#include "Vertex.h"

class cRoadSurfaceReader
{
private:
	const char* m_filePath;
public:
	cRoadSurfaceReader(const char* filePath) : m_filePath(filePath)
	{
	}

	virtual const std::vector<Vertex>& ReadRoadSurface();

	virtual void PrintFile()
	{
		std::ifstream file;
		file.open(m_filePath);
		std::string line;
		while (!file.eof()) {
			file >> line;
			std::cout << line << std::endl;
		}
	}

};
