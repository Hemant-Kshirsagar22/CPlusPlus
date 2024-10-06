#include <iostream>

class A
{
private:
	int aPrivate;
	void printAPrivate(void)
	{
		std::cout << aPrivate;
	}
protected:
	int aProtected;
	void printAProtected(void)
	{
		std::cout << aProtected;
	}
public:
	int aPublic;

	void printAPublic(void)
	{
		std::cout << aPublic;
	}
	
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
class B : protected A
{
private:
	int bPrivate;
protected:
	int bProtected;
public:
	int bPublic;
	B(int bPri = 0, int bPro = 0, int bPub = 0) : A(10, bPro + 10, bPub + 10)
	{
		bPrivate = bPri;
		bProtected = bPro;
		bPublic = bPub;
		std::cout << "B :: parameterized constructor\n";

		printAProtected();
		std::cout << std::endl;
		printAPublic();
		std::cout << std::endl;
		aPublic;
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
	
	std::cout << "class B : protected A can access only protected and Public members of A class inside Class B\nB class cannot access any data members outside class of Class A" << std::endl << std::endl;

	std::cout << "Public and protected members of the base class become protected members in the derived class.\nThis means they are accessible within the derived class and by any classes that further derive from this derived class, but not accessible from outside these classes.\n\n";
	return(0);
}
