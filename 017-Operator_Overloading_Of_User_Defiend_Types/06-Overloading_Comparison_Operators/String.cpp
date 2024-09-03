#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

class MyString
{
	const char *name;

public:
	explicit MyString(const char *s) : name(strdup(s)) {}
	~MyString(void)
	{
		std::free((void *)name);
	}

	const char *getName(void)
	{
		return(name);
	}

	friend bool operator==(const MyString &myStringOne, const MyString &myStringTwo)
	{
		return(!strcmp(myStringOne.name, myStringTwo.name));
	}

	friend bool operator==(const MyString &myStringOne, const std::string &stringTwo)
	{
		return(!strcmp(myStringOne.name, stringTwo.c_str()));
	}

	friend bool operator==(const std::string &stringOne, const MyString &myStringTwo)
	{
		return(!strcmp(stringOne.c_str(), myStringTwo.name));
	}
};

int main(void)
{
	MyString myStringOne("red");
	MyString myStringTwo("red");
	MyString myStringThree("blue");

	std::string stringOne("red");
	std::string stringTwo("red");
	std::string stringThree("blue");

	if (myStringOne == myStringTwo)
	{
		std::cout << myStringOne.getName() <<" == " << myStringTwo.getName() << std::endl;
	}
	else
	{
		std::cout << myStringOne.getName() << " != " << myStringTwo.getName() << std::endl;
	}

	if (myStringOne == myStringThree)
	{
		std::cout << myStringOne.getName() << " == " << myStringThree.getName() << std::endl;
	}
	else
	{
		std::cout << myStringOne.getName() << " != " << myStringThree.getName() << std::endl;
	}

	if (myStringOne == stringTwo)
	{
		std::cout << myStringOne.getName() << " == " << stringOne << std::endl;
	}
	else
	{
		std::cout << myStringOne.getName() << " != " << stringOne << std::endl;
	}

	if (myStringOne == stringThree)
	{
		std::cout << myStringOne.getName() << " == " << stringThree << std::endl;
	}
	else
	{
		std::cout << myStringOne.getName() << " != " << stringThree << std::endl;
	}

	if (stringOne == myStringTwo)
	{
		std::cout << stringOne << " == " << myStringTwo.getName() << std::endl;
	}
	else
	{
		std::cout << stringOne << " != " << myStringTwo.getName() << std::endl;
	}

	if (stringOne == myStringThree)
	{
		std::cout << stringOne << " == " << myStringThree.getName();
	}
	else
	{
		std::cout << stringOne << " != " << myStringThree.getName();
	}


	return(0);
}