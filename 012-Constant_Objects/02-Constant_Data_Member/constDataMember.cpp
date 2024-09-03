#include <iostream>

class MyClass
{
	const int cPriMem;
	int priMem;
public:
	const int cPubMem;
	int pubMem;

	MyClass(int cPri, int ncPri, int cPub, int ncPub) :
		cPriMem(cPri),
		priMem(ncPri),
		cPubMem(cPub),
		pubMem(ncPub)
	{}

	int getConstPri(void) {
		return(cPriMem);
	}

	void setConstPri(int i)	{
		//cPriMem = i; get error because cPriMem is constant
	}

	int getPri(void)
	{
		return(priMem);
	}
	void setPri(int i)
	{
		priMem = i;
	}
};

int main(void)
{
	MyClass myObj(1, 2, 3, 4);

	std::cout << myObj.getConstPri() << std::endl;
	myObj.setConstPri(6);
	
	std::cout << myObj.getPri() << std::endl;
	myObj.setPri(6);

	std::cout << myObj.cPubMem << std::endl;
	// myObj.cPubMem = 3;

	std::cout << myObj.pubMem << std::endl;
	myObj.pubMem = 3;
	return(0);
}
