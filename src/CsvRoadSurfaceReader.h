#pragma once
#include "RoadSurfaceReader.h"
#include <sstream>
class CsvRoadSurfaceReader :
    public cRoadSurfaceReader
{
public:
    CsvRoadSurfaceReader(const char* filePath);
};

