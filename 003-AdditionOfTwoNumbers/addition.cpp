#include <iostream>

int main(void)
{
	int numberOne = 0;
	int numberTwo = 0;

	std::cout << "Enter First Number : ";
	std::cin >> numberOne;

	std::cout << "Enter Second Number : ";
	std::cin >> numberTwo;

	int sum = numberOne + numberTwo;

	std::cout << numberOne << " + " << numberTwo << " = " << sum << std::endl;

	return(0);
}