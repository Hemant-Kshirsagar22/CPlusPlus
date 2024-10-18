// reinterpret cast converts any pointer type to any other pointer type, even of unrelated classes
// The operation result is a simple binary copy of the value from one pointer to the other
// All pointer conversions are allowed : neither the content pointed nor the pointer type
// itself is checked
// It can also cast pointers to or from integer types
// The format in which this integer value represents a pointer is platform - specific
// The only guarantee is that a pointer cast to an integer type large enough to fully
// contain it(such as intptr t), is guaranteed to be able to be cast back to a valid
// pointer(Refer to Module 26)
// The conversions that can be performed by reinterpret cast but not by static cast
// are low - level operations based on reinterpreting the binary representations of the types,
// which on most cases results in code which is system - specific, andthus non - portable

#include <iostream>

using namespace std;

class A {};
class B {};

int main(void)
{
	long i = 2;
	double d = 3.7;
	double *pd = &d;

	// i = pd;			// implicit -- error
	i = reinterpret_cast<long>(pd); // warning
	i = (long)pd;		// C-style 
	cout << pd << " " << i << endl;

	A *pA;
	B *pB;

	// pA = pB;		// implicit -- error
	pA = reinterpret_cast<A *>(pB);
	pA = (A *)pB; // C-Style

	return(0);
}
