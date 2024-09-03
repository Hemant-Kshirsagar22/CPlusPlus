#include <iostream>
#include <cmath>

class Complex {
private: // these variables can access only by its class method or members
	double real;
	double imaginory;

public:
	double norm()
	{
		return (std::sqrt((real * real) + (imaginory * imaginory)));
	}
};

int main(void)
{
	//Complex c = { 4.2,5.3 }; this line gives error because real and imaginory are private variables 
	Complex c;
	std::cout << c.norm();

	return(0);
}
