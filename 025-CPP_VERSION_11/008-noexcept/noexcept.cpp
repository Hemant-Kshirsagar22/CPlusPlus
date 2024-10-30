// if a function cannnot throw an exception or if the program is not written to handle exception thrown by a function, that function can be declared noexcept


#include <iostream>

int addition(int numberOne,int numberTwo) noexcept
{
	return(numberOne + numberTwo);
}

int main(void)
{
	int numberOne = 10;
	int numberTwo = 20;

	std::cout << numberOne << " + " << numberTwo << " = " << addition(numberOne,numberTwo) << std::endl;

	return(0);
}

