#include <iostream>

int main(void)
{
	int add(int, int, int);
	int add(int, int);

	int numberOne = 10;
	int numberTwo = 20;
	int numberThree = 30;

	std::cout << numberOne << " + " << numberTwo << " = " << add(numberOne, numberTwo) << std::endl;
	
	std::cout << numberOne << " + " << numberTwo << " + " << numberThree << " = " << add(numberOne, numberTwo,numberThree) << std::endl;

	return(0);

}

int add(int numberOne, int numberTwo)
{
	return(numberOne + numberTwo);
}

int add(int numberOne, int numberTwo, int numberThree)
{
	return(numberOne + numberTwo + numberThree);
}
