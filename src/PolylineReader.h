#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "Vector3.h"
#include "Polyline.h"

class cPolylineReader
{
private:
	const char* m_filePath;
public:
	cPolylineReader(const char* filePath) : m_filePath(filePath)
	{
	}

	virtual std::shared_ptr<Polyline> ReadPolyline();

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

