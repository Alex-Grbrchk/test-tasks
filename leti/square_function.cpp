#include "square_function.h"

void SquareFunction::setCoefficients(double new_a, double new_b, double new_c)
{
    a = new_a;
    b = new_b;
    c = new_c;
}

double SquareFunction::calculate(double x)
{
    return (a * x * x + b * x + c);
}

void SquareFunction::printFunction()
{
    std::cout << a << " * x^2 + " << b << " * x + " << c << '\n';
}

SquareFunction::SquareFunction(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

SquareFunction::SquareFunction()
{
}

int main()
{
    double a, b, c;
    double x_1, x_2;
    std::cin >> a >> b >> c;
    SquareFunction F;
    F.setCoefficients(a, b, c);
    std::cin >> x_1 >> x_2;
    if (x_1 < x_2)
    {
        F.printFunction();
        for (int i = x_1; i <= x_2; i++)
        {
            std::cout << "for x = " << i << ": f = " << F.calculate(i) << '\n';
        }
    }
    else{
        std::cout<<"x1 < x2 requared\n";
    }
    return 0;
}