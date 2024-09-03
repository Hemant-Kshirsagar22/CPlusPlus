#include <iostream>

class Complex
{
	double real;
	double imaginory;

public:
	
	Complex(double r = 0.0, double i = 0.0) : real(r), imaginory(i) {}
	friend std::ostream &operator<<(std::ostream &oStream, const Complex &complex);
	friend std::istream &operator>>(std::istream &iStream, Complex &complex);
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
