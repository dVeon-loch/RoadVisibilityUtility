#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"

class cPolylineReader
{
private:
	const char* m_filePath;
public:
	cPolylineReader(const char* filePath) : m_filePath(filePath)
	{
	}

	virtual std::vector<Vertex>& ReadPolyline();

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

