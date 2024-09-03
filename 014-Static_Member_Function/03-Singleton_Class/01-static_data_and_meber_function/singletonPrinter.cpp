#include <iostream>

class Printer
{
private :
	bool blackAndWhite;
	bool bothSided;
	static Printer *myPrinter;

	// private constructor so no one can create Printer object from outside from the class
	Printer(bool bw = false, bool bs = false) : blackAndWhite(bw), bothSided(bs)
	{
		std::cout << "Printer constructed " << std::endl;
	}


public:
	
	~Printer(void)
	{
		std::cout << "Printer Destructed" << std::endl;
	}

	static const Printer &printer(bool bw = false, bool bs = false)
	{
		if (!myPrinter)
		{
			myPrinter = new Printer(bw, bs);
		}

		return(*myPrinter);
	}

	void print(int nP) const 
	{
		std::cout << "Printing " << nP << " Pages" << std::endl;
	}
};

Printer *Printer::myPrinter = 0;

int main(void)
{
	Printer::printer().print(10);
	Printer::printer().print(20);

	delete &Printer::printer();
}

