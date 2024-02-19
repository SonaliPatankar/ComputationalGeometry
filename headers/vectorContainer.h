#pragma once
#include <vector>
#include "GeomVector.h"
 
namespace Utility
{
    class VectorContainer
    {
    public:
        VectorContainer();
 
        std::vector<Geometry::GeomVector> vectorList() const;
        void addVectorToVectorContainer(const Geometry::GeomVector &vector);
 
        ~VectorContainer();
 
    private:
        std::vector<Geometry::GeomVector> mVectorList;
    };
}