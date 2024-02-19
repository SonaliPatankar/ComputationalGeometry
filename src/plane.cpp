#include "../headers/plane.h"
#include "../headers/vector3D.h"
 
Geometry::Plane::Plane() : mNormal(Vector3D(0, 0, 0)), mPointOnPlane(Point3D(0, 0, 0)) {}
Geometry::Plane::Plane(const Geometry::Vector3D &normal, const Geometry::Point3D &pointOnPlane)
    : mNormal(normal), mPointOnPlane(pointOnPlane) {}
 
Geometry::Vector3D Geometry::Plane::normal() const
{
    return mNormal;
}
 
Geometry::Point3D Geometry::Plane::pointOnPlane() const
{
    return mPointOnPlane;
}
 
Geometry::Plane::~Plane() {}