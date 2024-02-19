#pragma once
#include "geomVector.h"
 
namespace Geometry
{
    class Plane
    {
    public:
        Plane();
        Plane(const Geometry::GeomVector &normal, const Geometry::Point3D &pointOnPlane);
        ~Plane()=default;
        Geometry::GeomVector normal() const;
        Point3D pointOnPlane() const;
    private:
        Geometry::GeomVector mNormal;
        Point3D mPointOnPlane;
    };
}