#pragma once
#include <string>
#include <vector>
#include "geomVector.h"
namespace Geometry
{
    class Writer
    {
    public:
        Writer()=default;
        ~Writer()=default;
        // Function to write geometry data to an STL file
        void write(const std::string &filePath, const std::vector<GeomVector> &vectors);
    };
}