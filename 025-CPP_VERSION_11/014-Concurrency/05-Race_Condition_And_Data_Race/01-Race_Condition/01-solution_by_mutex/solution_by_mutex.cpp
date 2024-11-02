#include <iostream>
#include <vector>
#include <thread> // thread, this_thread::sleep_for
#include <mutex> // mutex
#include <chrono> // shrono::milliseconds
#include <cstdlib> // rand()

using namespace std;

int accum = 0;	// init accumulator
mutex accum_mutex;	// mutex veriable

void square(int x)
{
	int p = x * x;

	int delay = (int)((double)std::rand() / (double)(RAND_MAX)*100);
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));

	accum_mutex.lock();	// gets the lock on accum_mutex
	accum += p;		// accumulate product
	accum_mutex.unlock();	// release the lock on accum_mutex
}

int main(void)
{
	int trial_count = 0;

	do
	{
		++trial_count;

		accum = 0;

		vector<thread> ths;

		for(int i = 1; i <= 20;i++)
		{
			ths.push_back(thread(&square,i));
		}


		for(auto& th : ths)
		{
			th.join();
		}
		cout << "trials = " << trial_count << " accum = " << accum << endl;
	}while(accum == 2870);

	return(0);
	
}

