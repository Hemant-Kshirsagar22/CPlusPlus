#include <iostream>

using namespace std;

class B
{
public:
	void f(void)
	{
		cout << "B::f()\n";
	}

	virtual void g(void)
	{
		cout << "B::g()\n";
	}
};

class D : public B
{
public:
	void f(void)
	{
		cout << "D::f()\n";
	}
	virtual void g(void)
	{
		cout << "D::g()\n";
	}
};

int main(void)
{
	B b;
	D d;

	B *pB = &b;
	B *pD = &d; // UPCAST

	B &rB = b;
	B &rD = d; // UPCAST

	b.f(); // B::f()
	b.g(); // B::g()

	d.f(); // D::f()
	d.g(); // D::g()

	pB->f(); // B::f() -- Static Binding
	pB->g(); // B::g() -- Dynamic Binding
	pD->f(); // B::f() -- Static Binding
	pD->g(); // D::f() -- Dynamic Binding

	rB.f(); // B::f(); -- Static Binding
	rB.g(); // B::g(); -- Dynamic Binding
	rD.f(); // B::f(); -- Static Binding
	rD.g(); // D::g(); -- Dynamic Binding
	return(0);
}
