#include <iostream>
#include <cmath>

class Complex
{
	double real;
	double imaginory;

public:
	Complex(double real, double imaginory) :
		real(real),
		imaginory(imaginory)
	{
		std::cout << "Coplex Constructor ";
		print();
	}

	Complex(const Complex &complex):
		real(complex.real),
		imaginory(complex.imaginory)
	{
		std::cout << "Coplex Constructor ";
		print();
	}

	~Complex(void)
	{
		std::cout << "Complex Destructor ";
		print();
	}

	double norm()
	{
		return(std::sqrt(real * real + imaginory * imaginory));
	}

	void print(void)
	{
		std::cout << "|" << real << "+j" << imaginory << "| = " << norm() << std::endl;
	}

};

int main(void)
{
	Complex complexOne(4.2, 5.3);
	Complex complexTwo(complexOne);
	Complex complexThree = complexTwo;

	complexOne.print();
	complexTwo.print();
	complexThree.print();
}
