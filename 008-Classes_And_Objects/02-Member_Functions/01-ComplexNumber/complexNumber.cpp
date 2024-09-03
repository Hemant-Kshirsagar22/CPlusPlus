#include <iostream>
#include <cmath>

class Complex {
public:
	double real;
	double imaginory;

	double normal()
	{
		return(std::sqrt((real * real) + (imaginory * imaginory)));
	}

	void print()
	{
		std::cout << std::endl << std::endl << "| " << real << " * " << imaginory << " | = " << normal() << std::endl;
	}
};

int main(void)
{
	Complex complex = { 4.2,5.3 };
	complex.print();
	return(0);
}
