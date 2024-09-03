#include <iostream>

// this method does not recommended as we break encapsulation
class Complex
{
public:
	double real;
	double imaginory;

	Complex(double r = 0.0, double i = 0.0) : real(r), imaginory(i) {}
};

std::ostream &operator<<(std::ostream &oStream, const Complex &complex)
{
	oStream << complex.real << " +j " << complex.imaginory << std::endl;
	return(oStream);
}

std::istream &operator>>(std::istream &iStream, Complex &complex)
{
	std::cout << "Enter real : ";
	iStream >> complex.real;

	std::cout << "Enter Imaginory : ";
	iStream >> complex.imaginory;

	return(iStream);
}

int main(void)
{
	Complex complex;

	std::cin >> complex;

	std::cout << complex;

	return(0);
}
