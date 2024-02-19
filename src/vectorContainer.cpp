#include "../headers/VectorContainer.h"
 
Utility::VectorContainer::VectorContainer() {}
 
std::vector<Geometry::GeomVector> Utility::VectorContainer::vectorList() const
{
    return mVectorList;
}
 
void Utility::VectorContainer::addVectorToVectorContainer(const Geometry::GeomVector &vector)
{
    mVectorList.push_back(vector);
}
 
Utility::VectorContainer::~VectorContainer() {}