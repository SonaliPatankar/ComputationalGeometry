#pragma once
#include <cmath>
#include "point3D.h"
#include "matrix.h"

namespace Geometry
{
    class Vector3D : public Point3D
    {
    public:
    Vector3D();
        Vector3D(double x, double y, double z);
        ~Vector3D();
        bool operator == (const Vector3D &other) const;
        double magnitude() const;
        Vector3D normalize() const;
        double dotProduct(const Vector3D &other) const;
        Vector3D crossProduct(const Vector3D &other) const;

        Vector3D operator + (const Vector3D &other) const;
        Vector3D operator - (const Vector3D &other) const;
        Vector3D operator * (const Vector3D &other) const;
        Vector3D operator / (const Vector3D &other) const;
        Vector3D setVectorLength(double newLength) const;

        Vector3D addScalar(double scalar) const;
        Vector3D subtractScalar(double scalar) const;
        Vector3D multiplyScalar(double scalar) const;
        Vector3D divideScalar(double scalar) const;

        double distanceBetweenVectors(const Vector3D &other) const;
        double distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const;
        double angleBetweenVectors(const Vector3D &other) const;
        double angleBetweenVectorAndPlane(const Geometry::Plane &plane) const;
        void angleBetweenVectorAndAxis() const;
        
        Vector3D multiplyMatrix(const LinearAlgebra::Matrix &matrix) const;
        Vector3D projectionOnVector(const Vector3D &otherVector) const;
        Vector3D projectVectorOnPlane(const Vector3D &vector,const Vector3D &planeNormal) const;
        void directionCosines() const;
        // Vector3D subtractScalar(double scalar) const;
        // Vector3D scalarDivision(double scalar) const;
    };
}
