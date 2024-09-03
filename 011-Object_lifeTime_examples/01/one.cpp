#include <iostream>

// global function declarations
int init_m1(int);
int init_m2(int);

class X
{
	//int m1_; // initialize 1st
	//int m2_; // initialize 2nd
	int m2_;  // class variable initializes by the sequence that we declare in the class
	int m1_;
public:
	X(int m1, int m2) :
		m1_(init_m1(m1)), // called 2nd
		m2_(init_m2(m2)) // called 1st
	{
		std::cout << "Constructor" << std::endl;
	}

	~X(void)
	{
		std::cout << "Distructor" << std::endl;
	}
};

int main(void)
{
	X a(2, 3); 
	return(0);
}

int init_m1(int m)
{
	std::cout << "init_m1_ : " << m << std::endl;
	return(m);
}

int init_m2(int m)
{
	std::cout << "init_m2_ : " << m << std::endl;
	return(m);
}

/*
* OUTPUT : 
* 
	init_m1_ : 2
	init_m2_ : 3
	Constructor
	Distructor

*/