// Dynamic Binding
#include <iostream>

using namespace std;

class B
{
public :
	virtual void f(void)
	{
		cout << "B::f()\n";
	}
};

class D : public B
{
public:
	virtual void f(void)
	{
		cout << "D::f()";
	}
};

int main(void)
{
	B b;
	D d;

	B *p = NULL;

	p = &b;
	p->f(); // B::f();

	p = &d;
	p->f(); // D::f();
	return(0);
}