#include <iostream>
#include <typeinfo>

int main(void)
{
	printf("\n");

	if (__cplusplus == 201703L)
	{
		std::cout << "version : C++ 17\n";
	}
	else if (__cplusplus == 201402L)
	{
		std::cout << "version : C++ 14\n";
	}
	else if (__cplusplus == 201103L)
	{
		std::cout << "version : C++ 11\n";
	}
	else if (__cplusplus == 199711L)
	{
		std::cout << "version : C++ 98\n";
	}
	else
	{
		std::cout << "pre-standard C++\n";
	}

	return(0);
}
