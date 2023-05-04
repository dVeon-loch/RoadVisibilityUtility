#pragma once
#include "PolylineReader.h"
#include <sstream>

class CsvPolylineReader :
    public cPolylineReader
{
public:
    CsvPolylineReader(const std::string& filePath);
};

