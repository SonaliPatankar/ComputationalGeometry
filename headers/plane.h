#pragma once
#include "vector3D.h"
 
namespace Geometry
{
    class Plane
    {
    public:
        Plane();
        Plane(const Geometry::Vector3D &normal, const Geometry::Point3D &pointOnPlane);
 
        Geometry::Vector3D normal() const;
        Point3D pointOnPlane() const;
 
        ~Plane();
 
    private:
        Geometry::Vector3D mNormal;
        Point3D mPointOnPlane;
    };
}