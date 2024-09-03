#include <iostream>
#include <string>

class Data 
{
	std::string id_;
public:
	Data(const std::string &id) : id_(id)
	{
		std::cout << "Constructor : " << id_ << std::endl;
	}

	~Data(void)
	{
		std::cout << "Destructor : " << id_ << std::endl;
	}
};

class MyClass
{
	static Data d2_;
	static Data d1_;
};

// order of definations defined by the sequence on its initializeation
Data MyClass::d1_("Obj_1"); // constructed 1st
Data MyClass::d2_("Obj_2"); // constructed 2st

//Data MyClass::d2_("Obj_2"); // constructed 1st
//Data MyClass::d1_("Obj_1"); // constructed 2st

int main(void)
{
	return(0);
}

/*
* NOTE: Static data members can access by only static member functions
*/