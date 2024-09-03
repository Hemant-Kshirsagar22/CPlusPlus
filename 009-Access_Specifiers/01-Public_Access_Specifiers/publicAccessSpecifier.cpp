#include <iostream>
#include <cmath>

class Complex
{
public:
	double real;
	double imaginory;

public:
	double norm()
	{
		return (std::sqrt((real * real) + (imaginory * imaginory)));
	}
};

void print(const Complex &t)
{
	std::cout << t.real << "+j" << t.imaginory << std::endl;
}

int main(void)
{
	Complex c = { 4.2, 5.3 };

	print(c);

	std::cout << c.norm();
}
