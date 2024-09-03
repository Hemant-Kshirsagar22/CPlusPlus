#include <iostream>

class Complex
{
	double real;
	double imaginory;

public:
	explicit Complex(double r = 0, double i = 0) : real(r), imaginory(i) // No implicit conversion is allowed
	{}

	void display(void)
	{
		std::cout << real << " +j " << imaginory << std::endl;
	}

	friend Complex operator+(const Complex &cOne, const Complex &cTwo)	// Overload 1
	{
		return(Complex(cOne.real + cTwo.real, cTwo.imaginory + cTwo.imaginory));
	}

	friend Complex operator+(const Complex &cOne,double dNumber) // Overload 2
	{
		Complex cTemp(dNumber); // create Temp object
		return(cOne + cTemp); // uses Overload 1
	}

	friend Complex operator+(double dNumber, const Complex &cOne) // Overload 3
	{
		Complex cTemp(dNumber);
		return(cTemp + cOne); // uses Overload 1
	}
};

int main(void)
{
	Complex cOne(2.5, 3.2);
	Complex cTwo(1.6, 3.3);
	Complex cThree;

	cThree = cOne + cTwo; // uses Overload 1
	cThree.display();

	cThree = cOne + 6.2; // uses Overload 2
	cThree.display();

	cThree = 4.2 + cTwo; // uses Overload 3
	cThree.display();

	return(0);
}
