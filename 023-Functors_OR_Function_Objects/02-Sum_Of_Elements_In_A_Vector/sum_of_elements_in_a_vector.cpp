#include <iostream>
#include <vector>
#include <algorithm>

struct adder
{
	double sum;
	adder() : sum(0) {}	

	void operator()(double x)
	{
		sum += x;
	}
};

struct display 
{
	void operator()(double x)
	{
		std::cout << x << " ";
	}
};

struct randInt
{

	int operator()(void)
	{
		return(rand() % 10);
	}
};

int main(void)
{
	std::vector<int> v(10);
	

	// filling vector with random values
	generate(v.begin(),v.end(),randInt());
	
	// displaying vector elements 
	for_each(v.begin(),v.end(),display());	
	std::cout << "\n\n";
	adder result = for_each(v.begin(),v.end(),adder());

	std::cout << "ADDITION OF VECTOR ELEMENTS IS : " << result.sum << std::endl;

	return(0);
}
