#include <iostream>

class MyClass 
{
	int mem;
	mutable int mutableMem;

public:
	MyClass(int m, int mm) : mem(m), mutableMem(mm) {}

	int getMem() const 
	{
		return mem;
	}

	void setMem(int i) 
	{
		mem = i; 
	}

	int getMutableMem() const
	{
		return(mutableMem);
	}

	void setMutableMem(int i) const
	{
		mutableMem = i;
	}
};

int main(void)
{
	const MyClass myConstObj(1, 2);

	std::cout << myConstObj.getMem() << std::endl;
	// myConstObj.setMem(3); // Error to invoke

	std::cout << myConstObj.getMutableMem() << std::endl;
	myConstObj.setMutableMem(4);
}
