#include <iostream>

class A
{
private:
	int aPrivate;
protected:
	int aProtected;
public:
	int aPublic;
	A() 
	{
		std::cout << "A :: default constructor\n";
	}
	A(int aPri, int aPro,int aPub)
	{
		aPrivate = aPri;
		aProtected = aPro;
		aPublic = aPub;
		std::cout << "A :: parameterized constructor\n";
	}

	~A()
	{
		std::cout << "A :: Destructor\n";
	}
};
class B : public A
{
private:
	int bPrivate;
protected:
	int bProtected;
public:
	int bPublic;
	B(int bPri = 0, int bPro = 0, int bPub = 0)
	{
		bPrivate = bPri;
		bProtected = bPro;
		bPublic = bPub;
		std::cout << "B :: parameterized constructor\n";
		aProtected;
	}

	~B()
	{
		std::cout << "B :: Destructor\n";
	}
};
int main(void)
{
	B b(10,20,30);
	std::cout << "Public Members: Public members of the base class remain public in the derived class. This means they are accessible from outside the derived class through objects of the derived class.\n\nProtected Members : Protected members of the base class remain protected in the derived class.They are accessible within the derived class and by classes derived from it, but not from outside these classes." << std::endl;
	return(0);
}
