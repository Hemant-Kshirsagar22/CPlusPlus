#include <iostream>

class Printer
{
private:
	bool blackAndWhilte;
	bool bothSided;
	Printer(bool bw = false, bool bs = false) : blackAndWhilte(bw), bothSided(bs)
	{
		std::cout << "Printer Constructed" << std::endl;
	}

	~Printer(void)
	{
		std::cout << "Printer destructed" << std::endl;
	}

public:
	static const Printer &printer(bool bw = false, bool bs = false)
	{
		static Printer myPrinter(bw, bs);

		return(myPrinter);
	}

	void print(int nP) const
	{
		std::cout << "Printing " << nP << " Pages" << std::endl;
	}
};

int main(void)
{
	Printer::printer().print(10);
	Printer::printer().print(20);

	return(0);
}
