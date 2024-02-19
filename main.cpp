#include <iostream>
#include <vector>
#include <string>
#include "./headers/geomVector.h"
#include "./headers/writer.h"
#include "./headers/matrix.h"
#include "./headers/plane.h"
#include "./headers/vectorContainer.h"
int main()
{
    int choice;
    double x1;
    double x2;
    double y1;
    double y2;
    double z1;
    double z2;
    char choice1;
    do
    {
        std::cout << "enter ypur choice" << std::endl
                  << "1. Check if two vectors are equal" << std::endl
                  << "2. Find magnitude of vector" << std::endl
                  << "3. Find normalized vector" << std::endl
                  << "4. Set new VectorLength" << std::endl
                  << "5. Add scalar value to vector" << std::endl
                  << "6. Subtract scalar value from vector" << std::endl
                  << "7. Multiply vector by scalar value" << std::endl
                  << "8. Divide vector by a scalar value" << std::endl
                  << "9. Add two vectors" << std::endl
                  << "10. DotProduct of two vectors" << std::endl
                  << "11. CrossProduct of two vectors" << std::endl
                  << "12. Find direction Cosines of vector" << std::endl
                  << "13. Multiply vector with matrix" << std::endl
                  << "14. Find distance between two vectors" << std::endl
                  << "15. Find distance between vector and plane" << std::endl
                  << "16. Find angle between two vectors" << std::endl
                  << "17. Find angle between vector and plane" << std::endl
                  << "18. Find projection on vector" << std::endl
                  << "19. Find projection on plane " << std::endl
                  << "20. Angle between vector and axis";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {           
            std::cout << "enter value for x, y and z" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            std::cout << "enter value for x, y and z" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector vector1(x1, y1, z1);
            Geometry::GeomVector vector2(x2, y2, z2);
            if (vector1 == vector2)
            {
                std::cout << "Two vectors are equal." << std::endl;
            }
            else
            {
                std::cout << "Two vectors are not equal." << std::endl;
            }
        }
        break;
        case 2:
        {
            std::cout << "enter value for x, y and z" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "Magnitude of two vector is " << vector1.magnitude() << std::endl;
        }
        break;

        case 3:
        {
            Utility::VectorContainer vectorContainer;            
            std::cout << "enter value for x, y and z" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            vectorContainer.addVectorToVectorContainer(vector1);
            Geometry::GeomVector result = vector1.normalize();
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;

        case 4:
        {
            Utility::VectorContainer vectorContainer;
            int newLength;
            std::cout << "enter value for x, y and z" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::vector<Geometry::GeomVector> vectors;
            vectorContainer.addVectorToVectorContainer(vector1);
            std::cout << "Enter new length " << std::endl;
            std::cin >> newLength;
            Geometry::GeomVector result = vector1.setVectorLength(newLength);
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }

        case 5:
        {
            Utility::VectorContainer vectorContainer;
            int scalarValue;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter integer value" << std::endl;
            std::cin >> scalarValue;
            Geometry::GeomVector result = vector1.addScalar(scalarValue);
            std::vector<Geometry::GeomVector> vectors;
            vectorContainer.addVectorToVectorContainer(vector1);;
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;

        case 6:
        {
            Utility::VectorContainer vectorContainer;
            int scalarValue;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter integer value" << std::endl;
            std::cin >> scalarValue;
            Geometry::GeomVector result = vector1.subtractScalar(scalarValue);
            vectorContainer.addVectorToVectorContainer(vector1);;
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;
        case 7:
        {
            Utility::VectorContainer vectorContainer;
            int scalarValue;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter integer value" << std::endl;
            std::cin >> scalarValue;
            Geometry::GeomVector result = vector1.multiplyScalar(scalarValue);
            vectorContainer.addVectorToVectorContainer(vector1);;
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;

        case 8:
        {
            Utility::VectorContainer vectorContainer;
            int scalarValue;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter integer value" << std::endl;
            std::cin >> scalarValue;
            Geometry::GeomVector result = vector1.divideScalar(scalarValue);
            vectorContainer.addVectorToVectorContainer(vector1);
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;

        case 9:
        {
            Utility::VectorContainer vectorContainer;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector vector2(x2, y2, z2);
            Geometry::GeomVector result = vector1 + vector2;
            vectorContainer.addVectorToVectorContainer(vector1);
            vectorContainer.addVectorToVectorContainer(vector2);
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        
        }
        break;

        case 10:
        {
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector vector2(x2, y2, z2);
            double result = vector1.dotProduct(vector2);
            std::cout << "dot product is " << result << std::endl;
           
        }
        break;

        case 11:
        {
            Utility::VectorContainer vectorContainer;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x, y and z value for vector2" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector vector2(x2, y2, z2);
            Geometry::GeomVector result = vector1.crossProduct(vector2);
            vectorContainer.addVectorToVectorContainer(vector1);
            vectorContainer.addVectorToVectorContainer(vector2);
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;

        case 12:
        { 
            std::cout << "enter x, y and z value for vector2" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            vector1.directionCosines();
        }
        break;

        case 13:
        {
            Utility::VectorContainer vectorContainer;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            double s, b, c, d, e, f, g, h, i;
            std::cout << "Enter the elements of the 3 x 3 matrix: ";
            std::cin >> s >> b >> c >> d >> e >> f >> g >> h >> i;
            LinearAlgebra::Matrix matrix(s, b, c, d, e, f, g, h, i);
            Geometry::GeomVector result = vector1.multiplyMatrix(matrix);
            vectorContainer.addVectorToVectorContainer(vector1);
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;

        case 14:
        {
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x,y and z value for vector2" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector vector2(x2, y2, z2);
            double result = vector1.distanceBetweenVectors(vector2);
            std::cout << "Distance between two vectors is " << result << std::endl;
        }
        break;

        case 15:
        {
            double x3;
            double y3;
            double z3;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x,y and z value for normal" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector normal(x2, y2, z2);
            std::cout << "enter 3 coordinates for point" << std::endl;
            std::cin >> x3 >> y3 >> z3;
            Geometry::Point3D point(x3, y3, z3);
            Geometry::Plane plane(normal, point);
            double result = vector1.distanceBetweenVectorAndPlane(plane);
            std::cout << "Distance between vector and plane is " << result << std::endl;
        }
        break;

        case 16:
        {
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x,y and z value for normal" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector vector2(x2, y2, z2);
            double result = vector1.angleBetweenVectors(vector2);
            std::cout << "Angle between two vectors is " << result << std::endl;
        }
        break;

        case 17:
        {
            double x3;
            double y3;
            double z3;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x,y and z value for normal" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector normal(x2, y2, z2);
            std::cout << "enter 3 coordinates for point" << std::endl;
            std::cin >> x3 >> y3 >> z3;
            Geometry::Point3D point(x3, y3, z3);
            Geometry::Plane plane(normal, point);
            double result = vector1.angleBetweenVectorAndPlane(plane);
            std::cout << "angle between vector and plane is " << result << std::endl;
        }
        break;

        case 18:
        {
            Utility::VectorContainer vectorContainer;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x,y and z value for normal" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector vector2(x2, y2, z2);
            Geometry::GeomVector result = vector1.projectionOnVector(vector2);
            vectorContainer.addVectorToVectorContainer(vector1);
            vectorContainer.addVectorToVectorContainer(vector2);
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;

        case 19:
        {
            Utility::VectorContainer vectorContainer;
            double x2;
            double y2;
            double z2;
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1 >> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            std::cout << "enter x,y and z value for normal" << std::endl;
            std::cin >> x2 >> y2 >> z2;
            Geometry::GeomVector normal(x2, y2, z2);
            Geometry::GeomVector result = vector1.projectVectorOnPlane(vector1, normal);
            vectorContainer.addVectorToVectorContainer(vector1);
            vectorContainer.addVectorToVectorContainer(normal);
            vectorContainer.addVectorToVectorContainer(result);
            Geometry::Writer writer;
            std::string filepath = "output/output.txt";
            writer.write(filepath, vectorContainer.vectorList());
        }
        break;

        case 20:
        {
            std::cout << "enter x, y and z value for vector1" << std::endl;
            std::cin >> x1 >> y1>> z1;
            Geometry::GeomVector vector1(x1, y1, z1);
            double result;
            int value;
            std::cout << "enter int value 0 for x-axis, 1 for y-axis or 2 for z-axis" << std::endl;
            std::cin >> value;
            result = vector1.angleBetweenVectorAndAxis(value);
        }
        break;
        default:
            break;
        }
        std::cout<<"do you want to continue(y/n) ?"<<std::endl;
        std::cin>>choice1;
    } while (choice1 == 'y');

    return 0;
}