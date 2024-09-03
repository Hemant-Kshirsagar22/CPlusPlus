#include <iostream>

int main(void)
{
	int a = 0;
	int &b = a; // b is reference of a

	// a and b have the same memory location
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "&a = " << &a << ",  &b = " << &b << std::endl;

	++a; // changing a appears as change in b
	std::cout << "a = " << a << ", b = " << b << std::endl;

	++b; // changing b also changes a
	std::cout << "a = " << a << ", b = " << b << std::endl;

	return(0);
}