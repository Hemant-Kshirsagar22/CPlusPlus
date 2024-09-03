#include <iostream>

class Complex
{
	double real, imaginoary;

public:
	Complex(double re = 0.0, double im = 0.0) : real(re), imaginoary(im) {} 
	~Complex(void) {}
	void display(void)
	{
		std::cout << real << "+j " << imaginoary << std::endl;
	}

	Complex operator+(const Complex &c)
	{
		Complex r;
		r.real = real + c.real;
		r.imaginoary = imaginoary + c.imaginoary;
		return(r);
	}
};

int main(void)
{
	Complex complexOne(4.5, 25.25);
	Complex complexTwo(8.3, 10.25);
	Complex result;

	std::cout << "1st Complex No : ";
	complexOne.display();

	std::cout << "2nd Complex No : ";
	complexTwo.display();

	result = complexOne + complexTwo;

	std::cout << "Sum = ";
	result.display();

	return(0);

}

