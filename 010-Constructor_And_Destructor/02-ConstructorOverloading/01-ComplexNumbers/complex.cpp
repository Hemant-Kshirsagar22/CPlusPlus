#include <iostream>
#include <cmath>

class Complex
{
private:
	double real;
	double imaginory;

public:
	Complex(double real, double imaginory) : real(real), imaginory(imaginory) {}
	Complex(double real) : real(real), imaginory(0) {}
	Complex() : real(0), imaginory(0) {}

	double norm(void)
	{
		return(std::sqrt(real * real + imaginory * imaginory));
	}

	void print(void)
	{
		std::cout << "| " << real << " + j" << imaginory << " | = " << norm() << std::endl;
	}

};

int main(void)
{
	Complex complexOne(4.2, 5.3);
	Complex complexTwo(4.2);
	Complex complexThree;

	complexOne.print();
	complexTwo.print();
	complexThree.print();

	return(0);
}
