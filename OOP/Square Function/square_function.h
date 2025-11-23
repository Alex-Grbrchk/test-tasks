#ifndef SQUARE_FUNCTION_H
#define SQUARE_FUNCTION_H

#include <iostream>

class SquareFunction
{
private:
    double a = 1.;
    double b = -2;
    double c = 1.;

public:
    SquareFunction();
    
    void setCoefficients(double new_a, double new_b, double new_c);
    double calculate(double x);
    void printFunction();

};

#endif