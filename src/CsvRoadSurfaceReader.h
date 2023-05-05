#pragma once
#include "RoadSurfaceReader.h"
#include <sstream>

/*
* A concrete implementation of the abstract RoadSurfaceReader for working with the CSV files given for this task.
*/
class CsvRoadSurfaceReader :
    public RoadSurfaceReader
{
public:
    CsvRoadSurfaceReader(const std::string& filePath);
};

