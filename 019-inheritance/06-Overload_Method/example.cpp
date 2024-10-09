#include <iostream>
// static binding
using namespace std;

class A
{
public:
	void f()
	{
		cout << "A::f()\n";
	}
};

class B : public A
{
public:
	using A::f; // To Overload rather than hide the base class function f(). It is introdced into the scope of B with a using declaration
	void f(int a) // overloads f()
	{
		cout << "B::f()\t" << a; 
	}
};

int main(void)
{
	B b; // function calls resolved at compile time

	b.f(); // A::f();
	b.f(10); // B::f(int)

	return(0);
}
