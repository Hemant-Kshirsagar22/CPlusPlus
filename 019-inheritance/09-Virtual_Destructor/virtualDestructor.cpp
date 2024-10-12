#include <iostream>

using namespace std;

class B
{
	int data;
public:
	B(int d) : data(d)
	{
		cout << "B()\n\n";
	}
	virtual ~B(void)
	{
		cout << "~B()\n\n";
	}

	virtual void print(void)
	{
		cout << data;
	}
};

class D : public B
{
	int *ptr;
public:
	D(int d1, int d2) : B(d1), ptr(new int(d2))
	{
		cout << "D()\n\n";
	}
	~D(void)
	{
		cout << "~D()";
	}
};

int main(void)
{
	B *p = new B(2);
	B *q = new D(3, 5);

	p->print();
	cout << "\n\n";
	q->print();
	cout << "\n\n";

	delete p;
	delete q;  // here destructor of d (type D) not called because destructor of B is not virtual hence here static binding happens because q is type of B. we have to set the destructor of B to virtual.
	
	return(0);
}

/*
* OUTPUT when ~B() is not virtual 
* B()
  B()

  D()

  2

  3

  ~B()

  ~B()
*
* OUTPUT when ~B() is virtual 
	B()

	B()

	D()

	2

	3

	~B()

	~D()~B()
*/