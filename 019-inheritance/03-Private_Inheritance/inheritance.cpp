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
class B : private A
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
		
		
	}

	~B()
	{
		std::cout << "B :: Destructor\n";
	}
	
};
int main(void)
{
	B b(10,20,30);
	
	std::cout << "class B : private A\n the public and protected members of the base class become private members of the derived class.\n\nThis means they are only accessible within the derived class itself, not from outside or even from classes derived from this derived class." << std::endl;

	return(0);
}
