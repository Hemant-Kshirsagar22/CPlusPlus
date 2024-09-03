#include <iostream>

class MyClass
{
	static int x; // Declaration of static variable ( static variable is not part of object it is part of a class )
public:
	void get(void)
	{
		x = 15;
	}
	void print(void)
	{
		x = x + 10;
		std::cout << "X = " << x << std::endl;
	}
};

int MyClass::x = 0; // define static data member

int main(void)
{
	MyClass myClassOne;
	MyClass myClassTwo;
	
	myClassOne.get();
	myClassOne.get();

	myClassOne.print();
	myClassTwo.print();

	return(0);
}
