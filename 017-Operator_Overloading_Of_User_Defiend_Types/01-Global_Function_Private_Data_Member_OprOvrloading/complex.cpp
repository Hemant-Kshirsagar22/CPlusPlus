#include <iostream>

class Complex
{
	double real;
	double imaginory;

public:
	Complex(double re = 0.0, double im = 0.0) : real(re), imaginory(im) {}
	~Complex(void) {}

	void display(void);
	double getReal(void);
	double getImaginory(void);
	void setReal(double);
	void setImaginory(double);
};

void Complex::display(void)
{
	std::cout << real << "+j " << imaginory << std::endl;
}

double Complex::getReal(void)
{
	return(real);
}
double Complex::getImaginory(void)
{
	return(imaginory);
}

void Complex::setReal(double real)
{
	Complex::real = real;
}

void Complex::setImaginory(double imaginory)
{
	Complex::imaginory = imaginory;
}

Complex operator+(Complex &t1, Complex &t2) {
	Complex sum;
	sum.setReal(t1.getReal() + t2.getReal());
	sum.setImaginory(t1.getImaginory() + t2.getImaginory());
	return sum;
}
int main(void)
{
	Complex complexOne(4.5, 25.25);
	Complex complexTwo(8.3, 10.25);
	Complex result;

	std::cout << "1st Complex No : " ;
	complexOne.display();

	std::cout << "2nd Complex No : ";
	complexTwo.display();

	result = complexOne + complexTwo;

	std::cout << "Sum = ";
	result.display();

	return(0);
}
