#include <iostream>
#include <thread>

struct Functor
{
	void operator()()
	{
		std::cout << "In Functor()()" << std::endl;
	}
};

int main(void)
{
	void function(void);
	
	std::thread t1{function}; // function() executes in separate Thread
	std::thread t2{Functor()}; // Functor()() executes in separate Thread
	

	t1.join();	// wait for t1
	t2.join();	// wait for t2
	return(0);
}

void function(void)
{
	std::cout << "in function()" << std::endl;
}


