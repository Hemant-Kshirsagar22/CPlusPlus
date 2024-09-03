#include <iostream>

class Complex
{
	double real;
	double imaginory;

public:
	explicit Complex(double r = 0, double i = 0) : real(r),imaginory(i) // No implicit conversion is allowed
	{} 

	void display(void)
	{
		std::cout << real << " +j " << imaginory << std::endl;
	}

	Complex operator+(const Complex &a) // overload 1
	{
		return(Complex(real + a.real, imaginory + a.imaginory));
	}

	Complex operator+(double d) // overload 2
	{
		Complex temp(d);	// create temporary object
		return(*this + temp); // use overload 1
	}
};

int main(void)
{
	Complex cOne(2.5, 3.2);
	Complex cTwo(1.6, 3.3);
	Complex cThree;

	cThree = cOne + cTwo;	// uses Overload 1
	cThree.display(); 

	cThree = cOne + 6.2;	// uses Overload 2
	cThree.display();

	// cThree = 4.2 + cTwo; // this is not possible needs an object on left side
	// cThree.display()
}