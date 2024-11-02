// Race condition : A race condition is a semantic error
// A race conidition is a situation, in which the result of an operation depends on the interleaving of certain individual operations


#include <iostream>
#include <vector>
#include <thread> // thread
#include <functional> // std::bind
#include <chrono>	// std::chorno::milliseconds

using namespace std;

int sum = 0;

void square(int x) // this function is called in different threads - one each for i .... 20
{
	sum = sum + (x * x); // compute and sum the square

	int delay = (int)((double)std::rand() / (double)(RAND_MAX)* 100);

	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

int main(void)
{
	int trial_count = 0;

	do
	{
		sum = 0;

		if(0 == trial_count % 100)
			std::cout << "tirals = " << trial_count << std::endl;

		std::vector<thread> squareThread; // vector of threads
	 
		for(int i = 1; i <= 20; i++)
		{
			squareThread.push_back(std::thread(std::bind(&square, i))); // 20 threads spawned
		}

		for(auto& th : squareThread)
		{
			th.join();	// join 20 threads
		}
	
		std::cout << "Accumulator : " << sum << endl;	// print the result
		trial_count++;

	}while(sum == 2870);
	return(0);
}

