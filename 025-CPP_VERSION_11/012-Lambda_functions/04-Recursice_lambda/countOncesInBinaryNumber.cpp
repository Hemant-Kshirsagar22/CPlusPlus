#include <iostream>
#include <functional>

int main(void)
{
	std::function<int(int)> countOnces; // declaration of function countOnces;

	countOnces = [&countOnces](int n)
	{
		return((n == 0) ? 0 : ( countOnces(n / 2) + (n % 2) ));
	};

	auto print = [&countOnces](int n)
	{
		std::cout << "Number Of 1s in " << n << " : " << countOnces(n) << std::endl;
	};

	print(5);
	print(2);
	print(10);
	return(0);
}


/*
 * 1st call 
 * suppose n = 5
 * countOnces(5) returns countOnces(5/2) + 5 % 2 = countOnces(2) + 1
 *
 * 2nd recursive call 
 * countOnces(2) returns countOnces(2/2) + 2 % 2 = countOnces(1) + 0
 *
 * 3rd recursive call
 * coutnOnces(1) returns coutnOnces (1 / 2) + 1 % 2 = countOnces(0) + 1
 *
 * 4th recursice call
 * coutnOnces(0) return 0
 *
 * then 0 returns to 3rd stack frame then the 3rd recursice call returns 0 + 1 means 1
 *
 * after that 3rd recursive call returns to 2nd call value is 1 + 0 means 1
 *
 * after that 2nd recursive call resurns to 1st call value is 1 + 1 = 2
 *
 * finally it returns 2 to print() and prints 2
 * */
