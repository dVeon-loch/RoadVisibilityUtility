#pragma once
#include "RoadSurfaceReader.h"
class cCsvRoadSurfaceReader :
    public cRoadSurfaceReader
{
public:
    cCsvRoadSurfaceReader(const char* filePath);
};

