#pragma once 
namespace LinearAlgebra
{
    class Matrix
    {
    public:
        Matrix();
        Matrix(double a, double b, double c, double d, double e, double f, double g, double h, double i);
 
        double element(int row, int col) const;
 
        ~Matrix();
 
    private:
        double matrix[3][3];
    };
}