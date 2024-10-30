// constexpr are expressions that can evaluate at run time

#include <iostream>

constexpr int numberOne = 100;

void f(int numberTwo)
{
	constexpr int numberThree = numberOne + 1; // we can evaluate it compile tiems 

	// constexpr int numberFour = numberTwo + 1; // Error numberOne is not compile time constant
	std::cout << numberThree << " ";

}

int main(void)
{
	f(10);
	return(0);
}

