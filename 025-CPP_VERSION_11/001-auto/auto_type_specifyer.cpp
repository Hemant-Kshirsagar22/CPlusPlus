#include <iostream>

int main(void)
{
	int a = 5;
	int &b = a;
	const int c = 7;
	const int &d = c;

	// auto never deduces adornments like cv-qualifier or reference
	auto a_auto = a;	// int
	auto b_auto = b;	// int
	auto c_auto = c;	// int
	auto d_auto = d;	// int
	

	// cv-qualifier or reference needs to be explicitly added 
	auto &b_auto_ref = a;	// int&
	const auto c_auto_const = a;	// const int

	return(0);
}
