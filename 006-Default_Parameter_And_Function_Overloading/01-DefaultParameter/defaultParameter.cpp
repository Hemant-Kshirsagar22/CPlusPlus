#include <iostream>

int main(void)
{
	int function(int = 10);
	int x = 5;
	int y = 0;

	y = function(x);
	std::cout << "y = " << y << std::endl;

	y = function();
	std::cout << "y = " << y << std::endl;

	return(0);
}

int function(int a)
{
	return(a);
}
