#include "square_function.h"

void SquareFunction::setCoefficients(double new_a, double new_b, double new_c)
{
    this->a = new_a;
    this->b = new_b;
    this->c = new_c;
}

double SquareFunction::calculate(double x)
{
    return (a * x * x + b * x + c);
}

void SquareFunction::printFunction()
{
    std::cout << a << " * x^2 + " << b << " * x + " << c << '\n';
}

SquareFunction::SquareFunction()
{
}

int main()
{
    double a, b, c;
    double x_1, x_2;
    SquareFunction F;
    std::cout << "Input coefficients: ";
    std::cin >> a >> b >> c;
    F.setCoefficients(a, b, c);
    std::cout << "Input range: ";
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