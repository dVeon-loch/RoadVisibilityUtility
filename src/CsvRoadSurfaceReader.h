#pragma once
#include "RoadSurfaceReader.h"
#include <sstream>
class cCsvRoadSurfaceReader :
    public cRoadSurfaceReader
{
public:
    cCsvRoadSurfaceReader(const char* filePath);
};

