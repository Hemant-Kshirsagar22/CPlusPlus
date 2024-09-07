#include <iostream>

/*
* NOTES:
* A namespace is a declarative region that provides a scope to the identifiers
* It is used to organize code into logical groups and to prevent name collisions that can
* occur especially when your code base inclueds multiple libraries
*/

using namespace std; // using this line we can avoid lengthy prefixes
namespace MyNameSpace  
{
	int myData;			// variable in namespace

	void myFunction(void) // function in namespace
	{
		std::cout << "MyNameSpace myFunction\n\n";
	}

	class MyClass			// class in namespace
	{
		int data;
	public:
		MyClass(int d) : data(d) {}
		void display(void)
		{
			std::cout << "MyClass data = " << data << std::endl;
		}
	};
}

int main(void)
{
	MyNameSpace::myData = 10;	// variable name qualified by namespace name

	std::cout << "MyNameSpace::myData = " << MyNameSpace::myData << std::endl;

	MyNameSpace::myFunction();	// function name qualified by namespace name

	MyNameSpace::MyClass obj(25); // class name  qualified by namespace name

	obj.display();
}

