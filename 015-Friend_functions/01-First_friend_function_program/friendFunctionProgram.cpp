#include <iostream>

/*
* NOTE:
* friend function : It is a function that can access the private and protected data members of a class that the function is a friend of.
*/
class MyClass
{
	int data;
public :
	MyClass(int i) : data(i) { }

	friend void display(const MyClass &); //  this line is used to make a friend function that means display function can access data variable
};

void display(const MyClass &);

int main(void)
{
	MyClass myClass(10);

	display(myClass);

	return(0);
}

void display(const MyClass &myClass)
{
	std::cout << "Data : " << myClass.data << std::endl;
}
