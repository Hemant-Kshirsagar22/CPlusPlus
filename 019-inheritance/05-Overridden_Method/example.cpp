#include <iostream>

using namespace std;

class B
{
public:
	void f()
	{
		cout <<"B::f()\n";
	}
};

class D : public B
{
public:
	void f()
	{
		cout << "D::f()";
	}
};

int main(void)
{
	B b;
	D d;

	b.f(); // B::f();
	d.f(); // overrides B::f() and print D::f()
	return(0);
}