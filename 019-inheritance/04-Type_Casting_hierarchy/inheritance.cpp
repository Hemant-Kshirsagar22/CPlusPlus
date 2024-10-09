#include <iostream>

class A
{
public : 
	int dataA;
};

class B : public A
{
public:
	int dataB;
};

int main(void)
{
	A a;
	B b;

	a.dataA = 2;
	b.dataA = 3;
	b.dataB = 5;

	A *pA = &a;
	B *pB = &b;

	std::cout << pA->dataA << std::endl;
	std::cout << pB->dataA << " " << pB->dataB << std::endl;

	pA = &b;	// up cast

	// pB = &a; // down cast is risky

	std::cout << pA->dataA;
	// std::cout << pA->dataB; // Error 'dataB' is not member of 'A'

	return(0);
}
