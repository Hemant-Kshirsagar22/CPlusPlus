// templates are specifications of a collection of functions or classes which are parameterized by types
// A template function in C++ allows you to write a function that can operate on different data types without needing to overload it for each type.
// syntax :
// template<typename / class>

#include <iostream>

template<class Type>
Type max(Type x, Type y)
{
	return(x > y ? x : y);
}

int main(void)
{
	int numberOne = 3;
	int numberTwo = 5;
	int maximumOne = 0;

	double numberThree = 2.1;
	double numberFour = 3.7;
	double maximumTwo = 0.0;

	maximumOne = max<int>(numberOne,numberTwo);
	std::cout << "max(" << numberOne << ", " << numberTwo << ") = " << maximumOne << std::endl;

	maximumTwo = max<double>(numberThree, numberFour);
	std::cout << "max(" << numberThree << ", " << numberFour << ") = " << maximumTwo << std::endl;

	return(0);
}

