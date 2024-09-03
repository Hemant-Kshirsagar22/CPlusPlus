#include <iostream>

class MyClass
{
	int data;
public:
	MyClass(int d) : data(d) {}

	MyClass &operator++(void) // overloading pre-increment
	{
		++data;
		return *this;
	}

	MyClass &operator++(int) // overloading post-increment
	{
		MyClass temp(data);
		++data;
		return(temp);
	}

	void display(void)
	{
		std::cout << "Data = " << data << std::endl;
	}
};

int main(void)
{
	MyClass objOne(8);
	objOne.display();

	MyClass objTwo = objOne++;
	objTwo.display();
	objOne.display();

	objTwo = ++objOne;
	objTwo.display();
	objOne.display();

	return(0);
}
