#pragma once
#include "PolylineReader.h"
#include <sstream>

/*
* A concrete implementation of the abstract PolylineReader for working with the CSV files given for this task.
*/
class CsvPolylineReader :
    public PolylineReader
{
public:
    CsvPolylineReader(const std::string& filePath);
};

