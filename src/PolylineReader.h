#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "Vector3.h"
#include "Polyline.h"

/*
* Abstract class for a generic polyline reader. Can be extended by concrete classes that work with specific file types.
*/
class PolylineReader
{
private:
	const std::string m_filePath;
public:
	PolylineReader(const std::string& filePath) : m_filePath(filePath)
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

