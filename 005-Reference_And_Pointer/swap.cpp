#include <iostream>

int main(void)
{
	void swap(int &, int &); // call by reference

	int a = 10;
	int b = 20;
	
	std::cout << "a = " << a << " & b = " << b << " to swap" << std::endl;
	swap(a, b);
	std::cout << "a = " << a << " & b = " << b << " on swap" << std::endl;

	return(0);
}

void swap(int &x, int &y)
{
	int temp = 0;

	temp = x;
	x = y;
	y = temp;
}
