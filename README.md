# C++ Basic Vector Operations
 
This C++ project provides implementations of basic vector operations. These operations include various functionalities to manipulate vectors, calculate distances, angles, and perform vector operations such as addition, subtraction, scalar operations, dot product, cross product, and more. 

## File Structure
 Files:
## Point3D.h/cpp: Defines a 3D point class with x, y, and z coordinates.

Point3D(double inX, double inY, double inZ = 0): Constructor for Point3D.
~Point3D(): Destructor for Point3D.
double x() const: Returns the x-coordinate of the point.
double y() const: Returns the y-coordinate of the point.
double z() const: Returns the z-coordinate of the point.
void setX(double inX): Sets the x-coordinate of the point.
void setY(double inY): Sets the y-coordinate of the point.
void setZ(double inZ): Sets the z-coordinate of the point.

# geomVector.h/ .cpp: Inherite Point3D class.Contains operations perfomed on vectors

- **bool Equality Check**: Determine if two vectors are equal.
- **double magnitude()**: Calculate the magnitude (length) of a vector.
- **GeomVector normalize() const**: Normalize a vector to unit length.
- **GeomVector setVectorLength(double newLength) const**: Set the length of a vector to a specified value.
- **GeomVector addScalar(double scalar) const**: Add a scalar value to each component of a vector.
- **GeomVector subtractScalar(double scalar) const**: Subtract a scalar value from each component of a vector.
- **GeomVector multiplyScalar(double scalar) const**: Multiply each component of a vector by a scalar value.
- **GeomVector divideScalar(double scalar) const**: Divide each component of a vector by a scalar value.
- **GeomVector operator + (const GeomVector &other) const;**: Add two vectors together.
- **double dotProduct(const GeomVector &other) const**: Calculate the dot product of two vectorss.
- **GeomVector crossProduct(const GeomVector &other) const**: Calculate the cross product of two vectors.
- **void directionCosines() const**: Calculate the direction cosines of a vector.
- **GeomVector multiplyMatrix(const LinearAlgebra::Matrix &matrix) const**: Multiply a vector by a matrix.
- **double distanceBetweenVectors(const GeomVector &other) const**: Calculate the Euclidean distance between two vectors.
- **double distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const**: Calculate the distance between a vector and a plane.
- **double angleBetweenVectors(const GeomVector &other) const**: Calculate the angle between two vectors.
- **double angleBetweenVectorAndAxis(int axis) const**: Calculate the angle between a vector and a specified axis.
- **double angleBetweenVectorAndPlane(const Geometry::Plane &plane) const**: Calculate the angle between a vector and a plane.
- **GeomVector projectionOnVector(const GeomVector &otherVector) const**: Calculate the projection of one vector onto another vector.
- **GeomVector projectVectorOnPlane(const GeomVector &vector,const GeomVector &planeNormal) const**: Calculate the projection of a vector onto a plane.

# vectorContainer.h/ .cpp: Contains list of vector
Create vector list.

# matrix.h/ .cpp: Contains 3*3 matrix
Create 3*3 matrix which is usedin one of geomVector operation

# output
1.Add a scalar value to each component of a vector.
![add_scalar](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/9edcce3d-3544-4227-8c5a-721e261d166c)

2.Subtract a scalar value to each component of a vector.
![subtract_scalar](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/3ac8d1e2-94e7-46f2-b389-8f19f3f1924c)

3.Multiply a scalar value to each component of a vector.
![multply_scalar](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/68e692d2-c4cf-4f87-8a2b-e7a3e16af243)

4.Divide a scalar value to each component of a vector.
![divide_scalar](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/1520d782-c390-4d89-851d-adc7af2fbce0)

5.Addition of two vectors
![add_vector](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/642b1841-01a8-4a19-8377-bf7b5296e3fe)

6.Cross product of two vectors
![cross_product](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/4f1a07da-12ec-4086-a69a-dc96581ecc30)

7.Multiply matrix and vector
![matrix](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/c5885536-e594-4ea1-8a0b-cd6265f9e72e)

8.Normalized Vector
![normalized_vector](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/4dc1fc37-516c-4663-af12-a06e67fe427a)

9.Set new length of vector
![set_length](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/b3d85d6e-4387-47cf-939e-6bd445adab00)

10.Project vector on vector
![project_vectoronvector](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/3a574140-cd81-4537-a773-e57be951af1b)

11. Project vector on plane
![project_vectoronplane](https://github.com/SonaliPatankar/ComputationalGeometry/assets/158050645/d80cf301-13af-4062-b264-74cd470c2b8f)
