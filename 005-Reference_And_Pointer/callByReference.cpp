#include <iostream>

int main(void)
{
	void function(int &, int);
	int a = 20;

	std::cout << "a = " << a << ", &a = " << &a << std::endl << std::endl;
	function(a, a);

	return(0);
}

void function(int &b, int c)
{
	std::cout << "b = " << b << ", &b = " << &b << std::endl << std::endl;
	std::cout << "c = " << c << ", &c = " << &c << std::endl << std::endl;
}
