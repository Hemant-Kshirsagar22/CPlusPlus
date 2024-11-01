#include <iostream>
#include <thread>
#include <vector>
#include <functional> // std::bind

void function(std::vector<int> &v, int *result)
{
	std::cout << "In function() " << " : ";
	*result = 0;	// function with output

	for(auto x : v)
	{
		std::cout << " " << x;
		*result = *result + x; // accumulate sum
	}

	std::cout << std::endl;
}

struct Functor
{
	std::vector<int> &v;
	int *result; // functor with output

	Functor(std::vector<int> &v,int *result) : v(v), result(result)
	{
		*result = 0;
	}

	void operator()(void)
	{
		std::cout << "In Functor()()" << " : ";

		for(auto x : v)
		{
			std::cout << " " << x;
			*result += x;
		}

		std::cout << std::endl; // accumlate sum
	}
};

int main(void)
{
	std::vector<int> my_vect {1,2,3,4,5};
	int resultOne = 0;
	int resultTwo = 0;

	std::thread t1{std::bind(function,my_vect,&resultOne)}; 
	std::thread t2{Functor(my_vect,&resultTwo)};

	t1.join();
	t2.join();

	std:: cout << resultOne << " " << resultTwo << "\n";

	return(0);
}

