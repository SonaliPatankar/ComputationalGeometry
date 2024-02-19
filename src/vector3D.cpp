#include <iostream>
#include "../headers/vector3D.h"
#include "../headers/plane.h"
Geometry :: Vector3D::Vector3D() : Point3D() {}
Geometry :: Vector3D::Vector3D(double x, double y, double z) : Point3D(x,y,z) {}
 
Geometry:: Vector3D :: Vector3D::~Vector3D() {}
 
 bool Geometry:: Vector3D :: operator == (const Vector3D &other) const
 {
        return ( ( other.x() == this->x() ) && ( other.y() == this->y() ) && ( other.z() == this->z() ) );
 }
double Geometry::Vector3D::dotProduct(const Vector3D &other) const {
    return (this->x() * other.x()) + (this->y() * other.y()) + (this->z() * other.z());
}

Geometry::Vector3D Geometry::Vector3D::crossProduct(const Vector3D& other) const {
    double newX = (this->y() * other.z()) - (this->z() * other.y());
    double newY = (this->z() * other.x()) - (this->x() * other.z());
    double newZ = (this->x() * other.y()) - (this->y() * other.x());
    return Vector3D(newX, newY, newZ);
}

double Geometry::Vector3D::magnitude() const {
    return sqrt(this->x()*this->x() + this->y()*this->y() + this->z()*this->z());
}

Geometry::Vector3D Geometry::Vector3D::normalize() const {
    double mag = magnitude();
    return Vector3D(this->x()/mag, this->y()/mag, this->z()/mag);
}

Geometry::Vector3D Geometry::Vector3D:: operator + (const Vector3D &other) const
{
    return Vector3D(this->x() + other.x(), this->y() + other.y(), this->z() + other.z());
}

Geometry::Vector3D Geometry::Vector3D:: operator - (const Vector3D &other) const
{
    return Vector3D(this->x() - other.x(), this->y() - other.y(), this->z() - other.z());
}

Geometry::Vector3D Geometry::Vector3D:: operator * (const Vector3D &other) const
{
    return Vector3D(this->x() * other.x(), this->y() * other.y(), this->z() * other.z());
}

Geometry::Vector3D Geometry::Vector3D:: operator / (const Vector3D &other) const
{
    return Vector3D(this->x() / other.x(), this->y() / other.y(), this->z() / other.z());
}

Geometry::Vector3D Geometry::Vector3D:: setVectorLength(double newLength) const
{
    return this->normalize().multiplyScalar( newLength );
}

Geometry::Vector3D Geometry::Vector3D::addScalar(double scalar) const {
    return Vector3D(this->x() + scalar, this->y() + scalar, this->z() + scalar);
}

Geometry::Vector3D Geometry::Vector3D::subtractScalar(double scalar) const {
    return Vector3D(this->x() - scalar, this->y() - scalar, this->z() - scalar);
}


Geometry::Vector3D Geometry::Vector3D::multiplyScalar(double scalar) const {
    return Vector3D(this->x() * scalar, this->y() * scalar, this->z() * scalar);
}

Geometry::Vector3D Geometry::Vector3D::divideScalar(double scalar) const {
    return Vector3D(this->x() / scalar, this->y() / scalar, this->z() / scalar);
}

double Geometry::Vector3D::distanceBetweenVectors(const Vector3D& other) const {
    double dx = this->mX - other.x();
    double dy = this->mY - other.y();
    double dz = this->mZ - other.z();
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double Geometry::Vector3D::distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const
{ 
    double dX = x() - plane.pointOnPlane().x();
    double dY = y() - plane.pointOnPlane().y();
    double dZ = z() - plane.pointOnPlane().z();
    double dotProduct = dX * plane.normal().x() + dY * plane.normal().y() + dZ * plane.normal().z();
    double distance = std::abs(dotProduct) / plane.normal().magnitude();
    return distance;
}

double Geometry::Vector3D :: angleBetweenVectors(const Vector3D &other) const
{
    double dotProductResult = this->dotProduct(other);
    double magnitudeResult = magnitude() * other.magnitude();
    std::cout << "1: " << dotProductResult << "2: " << magnitudeResult << std::endl;
    double angleradians = acos(dotProductResult / magnitudeResult);
    // converting radians to degrees
    return angleradians * (180.0 / M_PI);
}

double Geometry::Vector3D::angleBetweenVectorAndPlane(const Geometry::Plane &plane) const
{
    // dot product (vector and plane's normal)
    double dotProductResult = dotProduct(plane.normal());
    // magnitude of vector and plane's normal
    double vectorMagnitude = magnitude();
    double normalMagnitude = plane.normal().magnitude();
 
    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * normalMagnitude));
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

void Geometry::Vector3D :: directionCosines() const
{
    double magnitudeResult = magnitude();
    double alpha;
    double beta;
    double gamma;
    // Ensure the magnitude is not zero to avoid division by zero
    if (magnitudeResult != 0.0) {
        alpha = std::acos(this->x() / magnitude()) * (180.0 / M_PI);
        beta = std::acos(this->y() / magnitude()) * (180.0 / M_PI);
        gamma = std::acos(this->z() / magnitude()) * (180.0 / M_PI);
    } else {
        // Handle the case when the magnitude is zero
        alpha = beta = gamma = 0.0;
    }
    std::cout<<"alpha :"<<alpha<<"beta :"<<beta<<"gamma :"<<gamma<<std::endl;
}

Geometry::Vector3D Geometry::Vector3D::multiplyMatrix(const LinearAlgebra::Matrix &matrix) const
{
    double resultX = x() * matrix.element(0, 0) + y() * matrix.element(1, 0) + z() * matrix.element(2, 0);
    double resultY = x() * matrix.element(0, 1) + y() * matrix.element(1, 1) + z() * matrix.element(2, 1);
    double resultZ = x() * matrix.element(0, 2) + y() * matrix.element(1, 2) + z() * matrix.element(2, 2);
    return Geometry::Vector3D(resultX, resultY, resultZ);
}

Geometry::Vector3D Geometry::Vector3D::projectionOnVector(const Vector3D &otherVector) const
{
    double dotProductResult = dotProduct(otherVector);
    double denominator = otherVector.dotProduct(otherVector);
 
    if (std::abs(denominator) == 0)
    {
        return Vector3D();
    }
 
    double scalarValue = dotProductResult / denominator;
    return otherVector.multiplyScalar(scalarValue);
}

Geometry::Vector3D Geometry::Vector3D::projectVectorOnPlane(const Vector3D &vector, const Vector3D &planeNormal) const
{
    Vector3D projection = vector.projectionOnVector(planeNormal);
    Vector3D result = vector - projection;
    return result;
}