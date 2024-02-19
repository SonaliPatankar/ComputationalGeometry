#pragma once
#include "geomVector.h"
 
namespace Geometry
{
    class Plane
    {
    public:
        Plane();
        Plane(const Geometry::GeomVector &normal, const Geometry::Point3D &pointOnPlane);
 
        Geometry::GeomVector normal() const;
        Point3D pointOnPlane() const;
 
        ~Plane();
 
    private:
        Geometry::GeomVector mNormal;
        Point3D mPointOnPlane;
    };
}