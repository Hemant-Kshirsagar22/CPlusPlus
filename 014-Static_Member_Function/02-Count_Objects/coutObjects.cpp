#include <iostream>
#include <string>

class MyClass
{
	std::string id;
	static int numberOfObjectsCreated;
	static int numberOfObjectsDestroyed;

public:
	MyClass(const std::string &id) : id(id)
	{
		numberOfObjectsCreated++;
		std::cout << "Constructor : " << id << " ";
		getLiveObj();
	}

	~MyClass(void)
	{
		numberOfObjectsDestroyed++;
		std::cout << "Destructor : " << id << " ";
		getLiveObj();
	}

	static int getObjConstructed(void)
	{
		return(numberOfObjectsCreated);
	}

	static int getObjDestructed(void)
	{
		return(numberOfObjectsDestroyed);
	}

	static int getLiveObj(void)
	{
		int nLive = numberOfObjectsCreated - numberOfObjectsDestroyed;
		
		std::cout << "Live Objects : " << nLive << std::endl;

		return(nLive);
	}
};

int MyClass::numberOfObjectsCreated = 0;
int MyClass::numberOfObjectsDestroyed = 0;

int numberOne(MyClass::getLiveObj());

MyClass gObj("gObj");

int numberTwo(MyClass::getLiveObj());

int main(void)
{
	MyClass objOne("objOne");

	MyClass *objTwo = new MyClass("objTwo");

	{
		MyClass objThree("objThree");
	}

	MyClass::getLiveObj();

	return(0);
}
