#pragma once
#include "PolylineReader.h"
#include <sstream>

class cCsvPolylineReader :
    public cPolylineReader
{
public:
    cCsvPolylineReader(const char* filePath);
};

