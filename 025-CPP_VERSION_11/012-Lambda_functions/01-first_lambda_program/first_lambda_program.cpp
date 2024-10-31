// lambda as syntactically lightweight way to define functions on the fly lambda can capture (or close over) variables from the surrounding scope- by value or by reference
//
// syntax
// [capture list] (paramter list) -> return-type { function body }
//
// capture list and parameter list can be empty so the following is a valid lambda
// parameter list is a sequence of parameter types and variable names as for an ordinary function
// function body is like an ordinary function body
// 	if the function body has only one reutrn statement (which is very common), the return type is assumend to be the same as the type of value veing returned
// 	if there is no return statement in the function body, the return type is assumed to be void


#include <iostream>

auto lambda = [] (int a) -> int { return(a+3); };

int main(void)
{
	std::cout << "lambda(5) = " << lambda(5) << std::endl; 
	return(0);
}

