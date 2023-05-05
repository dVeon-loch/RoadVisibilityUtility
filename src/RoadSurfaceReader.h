#pragma once

#include <vector>
#include<iostream>
#include <fstream>
#include <memory>

#include "Triangle.h"

/*
* Abstract class for a generic road surface reader. Can be extended by concrete classes that work with specific file types.
*/
class RoadSurfaceReader
{
private:
	const std::string m_filePath;
public:
	RoadSurfaceReader(const std::string& filePath) : m_filePath(filePath)
	{
	}

	virtual const std::shared_ptr<std::vector<Triangle>> ReadRoadSurface();

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

