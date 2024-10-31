#include <iostream>
#include <functional>
int main(void)
{
	std::function<int(int)> factorial;

	factorial = [&factorial](int n)
	{
		return(n == 0 ? 1 : factorial(n-1) * n);
	};

	std::cout << "factorial(5) : " << factorial(5) << std::endl;

	return(0);	
}
