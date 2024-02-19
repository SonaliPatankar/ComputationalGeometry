#include "../headers/plane.h"
#include "../headers/geomVector.h"
 
Geometry::Plane::Plane() : mNormal(GeomVector(0, 0, 0)), mPointOnPlane(Point3D(0, 0, 0)) {}
Geometry::Plane::Plane(const Geometry::GeomVector &normal, const Geometry::Point3D &pointOnPlane)
    : mNormal(normal), mPointOnPlane(pointOnPlane) {}
 
Geometry::GeomVector Geometry::Plane::normal() const
{
    return mNormal;
}
 
Geometry::Point3D Geometry::Plane::pointOnPlane() const
{
    return mPointOnPlane;
}
 
Geometry::Plane::~Plane() {}