#include <iostream>

using namespace std;

int main(void)
{
	int i = 2;
	long j;
	double d = 3.7;

	int *pi = &i;
	double *pd = &d;
	void *pv = 0;

	i = d;						// implicit -- warning
	i = static_cast<int>(d);
	i = (int)d;					// c-style casting

	d = i;						// implicit
	d = static_cast<double>(i); 
	d = (double)i;				// c-style casting

	pv = pi;
	// pi = pv; error for implicit cast
	pi = static_cast<int *>(pv);
	pi = (int *)pv;				// c-style casting

	// j = pd;					// implicit -- error
	// j = static_cast<long>(pd);  // error
	//j = (long)pd;				// C-style casting sizeof(long) = 8 = sizeof(double*) RISKY : should use reinterpret_cast
	
	// i = (int)pd;				// C-style -- error sizeof(int) = 4 != sizeof(double*)
	return(0);
}