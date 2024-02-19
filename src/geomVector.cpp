#include <iostream>
#include "../headers/geomVector.h"
#include "../headers/plane.h"
Geometry :: GeomVector::GeomVector() : Point3D() {}
Geometry :: GeomVector::GeomVector(double x, double y, double z) : Point3D(x,y,z) {}
 
// Overloaded equality operator for comparing two vectors
bool Geometry:: GeomVector :: operator == (const GeomVector &other) const
 {
        return ( ( other.x() == this->x() ) && ( other.y() == this->y() ) && ( other.z() == this->z() ) );
 }
 
// Calculate the dot product of two vectors
double Geometry::GeomVector::dotProduct(const GeomVector &other) const {
    return (this->x() * other.x()) + (this->y() * other.y()) + (this->z() * other.z());
}

// Calculate the cross product of two vectors and return new vector
Geometry::GeomVector Geometry::GeomVector::crossProduct(const GeomVector& other) const {
    double newX = (this->y() * other.z()) - (this->z() * other.y());
    double newY = (this->z() * other.x()) - (this->x() * other.z());
    double newZ = (this->x() * other.y()) - (this->y() * other.x());
    return GeomVector(newX, newY, newZ);
}

//Calculate the magnitude (length) of a vector.
double Geometry::GeomVector::magnitude() const {
    return sqrt(this->x()*this->x() + this->y()*this->y() + this->z()*this->z());
}

//Normalize a vector to unit length
Geometry::GeomVector Geometry::GeomVector::normalize() const {
    double mag = magnitude();
    if( mag != 0)
        return GeomVector(this->x()/mag, this->y()/mag, this->z()/mag);
    else
        return GeomVector(0.0,0.0, 0.0);
}

//Overload + operator to add two vectors and return new vector
Geometry::GeomVector Geometry::GeomVector:: operator + (const GeomVector &other) const
{
    return GeomVector(this->x() + other.x(), this->y() + other.y(), this->z() + other.z());
}

//Overload - operator to subtract two vectors and return new vector
Geometry::GeomVector Geometry::GeomVector:: operator - (const GeomVector &other) const
{
    return GeomVector(this->x() - other.x(), this->y() - other.y(), this->z() - other.z());
}

//Overload * operator to multiply two vectors and return new vector
Geometry::GeomVector Geometry::GeomVector:: operator * (const GeomVector &other) const
{
    return GeomVector(this->x() * other.x(), this->y() * other.y(), this->z() * other.z());
}

//Overload / operator to divide two vectors and return new vector
Geometry::GeomVector Geometry::GeomVector:: operator / (const GeomVector &other) const
{
    return GeomVector(this->x() / other.x(), this->y() / other.y(), this->z() / other.z());
}

//Set the length of a vector to a specified value
Geometry::GeomVector Geometry::GeomVector:: setVectorLength(double newLength) const
{
    //normalize the vector and then change it's magnitude
    return this->normalize().multiplyScalar( newLength );
}

//Add a scalar value to each component of a vector
Geometry::GeomVector Geometry::GeomVector::addScalar(double scalar) const {
    return GeomVector(this->x() + scalar, this->y() + scalar, this->z() + scalar);
}

//Subtract a scalar value from each component of a vector
Geometry::GeomVector Geometry::GeomVector::subtractScalar(double scalar) const {
    return GeomVector(this->x() - scalar, this->y() - scalar, this->z() - scalar);
}

//Multiply each component of a vector by a scalar value
Geometry::GeomVector Geometry::GeomVector::multiplyScalar(double scalar) const {
    return GeomVector(this->x() * scalar, this->y() * scalar, this->z() * scalar);
}

//Divide each component of a vector by a scalar value
Geometry::GeomVector Geometry::GeomVector::divideScalar(double scalar) const {
    return GeomVector(this->x() / scalar, this->y() / scalar, this->z() / scalar);
}

//Calculate the Euclidean distance between two vectors
double Geometry::GeomVector::distanceBetweenVectors(const GeomVector& other) const {
    double dx = this->mX - other.x();
    double dy = this->mY - other.y();
    double dz = this->mZ - other.z();
    return sqrt(dx*dx + dy*dy + dz*dz);
}

//Calculate the distance between a vector and a plane
double Geometry::GeomVector:: distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const
{ 
    double dX = x() - plane.pointOnPlane().x();
    double dY = y() - plane.pointOnPlane().y();
    double dZ = z() - plane.pointOnPlane().z();
    double dotProduct = dX * plane.normal().x() + dY * plane.normal().y() + dZ * plane.normal().z();
    double distance = std::abs(dotProduct) / plane.normal().magnitude();
    return distance;
}

//Calculate the angle between two vectors
double Geometry::GeomVector :: angleBetweenVectors(const GeomVector &other) const
{
    double dotProductResult = this->dotProduct(other);
    double magnitudeResult = magnitude() * other.magnitude();
    std::cout << "1: " << dotProductResult << "2: " << magnitudeResult << std::endl;
    double angleradians = acos(dotProductResult / magnitudeResult);
    // converting radians to degrees
    return angleradians * (180.0 / M_PI);
}

//Calculate the angle between a vector and a plane
double Geometry::GeomVector::angleBetweenVectorAndPlane(const Geometry::Plane &plane) const
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

//Calculate the direction cosines of a vector
void Geometry::GeomVector :: directionCosines() const
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

// Multiply a vector by a matrix
Geometry::GeomVector Geometry::GeomVector::multiplyMatrix(const LinearAlgebra::Matrix &matrix) const
{
    double resultX = x() * matrix.element(0, 0) + y() * matrix.element(1, 0) + z() * matrix.element(2, 0);
    double resultY = x() * matrix.element(0, 1) + y() * matrix.element(1, 1) + z() * matrix.element(2, 1);
    double resultZ = x() * matrix.element(0, 2) + y() * matrix.element(1, 2) + z() * matrix.element(2, 2);
    return Geometry::GeomVector(resultX, resultY, resultZ);
}

//Calculate the projection of one vector onto another vector
Geometry::GeomVector Geometry::GeomVector::projectionOnVector(const GeomVector &otherVector) const
{
    double dotProductResult = dotProduct(otherVector);
    double denominator = otherVector.dotProduct(otherVector);
 
    if (std::abs(denominator) == 0)
    {
        return GeomVector();
    }
 
    double scalarValue = dotProductResult / denominator;
    return otherVector.multiplyScalar(scalarValue);
}

//Calculate the projection of a vector onto a plane.
Geometry::GeomVector Geometry::GeomVector::projectVectorOnPlane(const GeomVector &vector, const GeomVector &planeNormal) const
{
    GeomVector projection = vector.projectionOnVector(planeNormal);
    GeomVector result = vector - projection;
    return result;
}

// calculates angle between vector and axis
double Geometry::GeomVector::angleBetweenVectorAndAxis(int axis) const
{
    double dotProductResult = 0.0;
    double vectorMagnitude = magnitude();
    double axisMagnitude = 1.0;
 
    // x-axis
    if (axis == 0)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = x();
    }
    // y-axis
    else if (axis == 1)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = y();
    }
    // z-axis
    else if (axis == 2)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = z();
    }
 
    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * axisMagnitude));
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}