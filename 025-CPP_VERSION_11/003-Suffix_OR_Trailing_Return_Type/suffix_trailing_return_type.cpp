// if we are defining the template suppose multiply function template and we pass it two different type then suffix return type helps to identify the return type of the function

#include <iostream>

template<typename typeOne,typename typeTwo>
// ??? multiply(typeOne x, typeTwo y) { return (x*y); }
// with the help of decltype/auto we can find the return type of multiply function
// using decltype
// decltype((*(typeOne *)0) * (*(typeTwo*)0)) multiply(typeOne x,typeTwo y)
// {
//	return(x * y);
// }

// using auto 
auto multiply(typeOne x,typeTwo y) -> decltype(x*y) 
{
	return(x * y);
}

int main(void)
{
	int numberOne = 10;
	long numberTwo = 300;
	float numberThree = 7.8f;

	std::cout << numberOne << " * " << numberThree  << " = " << multiply(numberOne,numberThree) << std::endl;

	return(0);
		
}

