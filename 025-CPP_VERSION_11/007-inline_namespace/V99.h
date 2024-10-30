#include <iostream>

inline namespace V99 // if you want to use V99 namespace default declare it inline
{
	void f(int n)
	{
		std::cout << "V99 n : " << n << std::endl;
	}
	void f(double d)
	{
		std::cout << "V99 n : " << d << std::endl;
	}
}
