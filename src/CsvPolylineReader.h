#pragma once
#include "PolylineReader.h"
class cCsvPolylineReader :
    public cPolylineReader
{
public:
    cCsvPolylineReader(const char* filePath);
};

