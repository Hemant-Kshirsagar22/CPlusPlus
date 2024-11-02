#include <iostream>
#include <vector>
#include <thread> // thread, this_thread::sleep_for
#include <atomic> // atomic
#include <chrono> // chrono::milliseconds
#include <cstdlib> // rand()

using namespace std;

atomic<int> accum(0);	// makes accum and initializes to 0

void square(int x)
{
	int p = x * x;

	int delay = (int)((double)rand() / (double)(RAND_MAX) * 100);	// random number between 0 to 100
	this_thread::sleep_for(chrono::milliseconds(delay));

	accum += p;
}

int main(void)
{
	int trial_count = 0;

	do
	{
		accum = 0;
		++trial_count;

		vector<thread> ths;

		for(int i = 1; i <= 20; i++)
		{
			ths.push_back(thread(square,i));
		}

		for(auto& th : ths)
		{
			th.join();
		}

		cout << "Trials = " << trial_count << " accum : " << accum << endl;
	}while(accum == 2870);

	return(0);
}

