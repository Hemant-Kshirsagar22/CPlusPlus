#include <iostream>
#include <thread>
#include <vector>
#include <functional> // std::bind()

void function(std::vector<int> &vect)
{
	std::cout << "In function()" << ": ";
	for(auto v : vect)
	{
		std::cout << v << " ";
	}

	std::cout << std::endl;
}

struct Functor
{
	private:
		std::vector<int> &vect;
	public:
	Functor(std::vector<int> &v) : vect(v) {}

	void operator()()
	{
//		std::cout << std::endl;
		std::cout << "In Functor()() " << " : ";

		for(auto v : vect)
		{
			std::cout << v << " ";
		}

		std::cout << std::endl;
	}
};

int main(void)
{
	std::vector<int> my_vect {1,2,3,4,5}; // init vector
	
	std::thread t1{std::bind(function,my_vect)}; // function(my_vect) executes in separate Thread
	std::thread t2{Functor(my_vect)}; 	// Functor(my_vect) executes in separate thread

	t1.join();
	t2.join();

	return(0);
}

