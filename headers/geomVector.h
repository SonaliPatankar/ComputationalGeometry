#pragma once
#include <cmath>
#include "point3D.h"
#include "matrix.h"

namespace Geometry
{
 class Plane;
    class GeomVector : public Point3D
    {
    public:
    GeomVector();
        GeomVector(double x, double y, double z);
        ~GeomVector();
        bool operator == (const GeomVector &other) const;
        double magnitude() const;
        GeomVector normalize() const;
        double dotProduct(const GeomVector &other) const;
        GeomVector crossProduct(const GeomVector &other) const;

        GeomVector operator + (const GeomVector &other) const;
        GeomVector operator - (const GeomVector &other) const;
        GeomVector operator * (const GeomVector &other) const;
        GeomVector operator / (const GeomVector &other) const;
        GeomVector setVectorLength(double newLength) const;

        GeomVector addScalar(double scalar) const;
        GeomVector subtractScalar(double scalar) const;
        GeomVector multiplyScalar(double scalar) const;
        GeomVector divideScalar(double scalar) const;

        double distanceBetweenVectors(const GeomVector &other) const;
        double distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const;
        double angleBetweenVectors(const GeomVector &other) const;
        double angleBetweenVectorAndPlane(const Geometry::Plane &plane) const;
        void angleBetweenVectorAndAxis() const;
        
        GeomVector multiplyMatrix(const LinearAlgebra::Matrix &matrix) const;
        GeomVector projectionOnVector(const GeomVector &otherVector) const;
        GeomVector projectVectorOnPlane(const GeomVector &vector,const GeomVector &planeNormal) const;
        void directionCosines() const;
        // Vector3D subtractScalar(double scalar) const;
        // Vector3D scalarDivision(double scalar) const;
    };
}
