#include <iostream>

class AdditionFunctor
{
	public:
	int operator()(int numberOne, int numberTwo) // this is functor
	{
		return(numberOne + numberTwo);
	}
};

int main(void)
{
	int additionFunction(int,int);
	
	int numberOne = 10;
	int numberTwo = 20;

	std::cout << "Addition Using Function : " << numberOne << " + " << numberTwo << " = " << additionFunction(numberOne, numberTwo) << std::endl << std::endl; 

	AdditionFunctor additionFunctor;

	std::cout << "Addition Using Functor : " << numberOne << " + " << numberTwo << " = " << additionFunctor(numberOne,numberTwo) << std::endl;

	return(0);
}

int additionFunction(int numberOne, int numberTwo)
{
	return(numberOne + numberTwo);
}


