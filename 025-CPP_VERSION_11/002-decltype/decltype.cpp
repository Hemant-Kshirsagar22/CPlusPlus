#include <iostream>

int main(void)
{
	int a = 5;
	int &b = a;
	const int c = 7;
	const int &d = c;

	// decltype deduces the complete type of th expression
	decltype(a) a_dt = a;	// int
	decltype(b) b_dt = b;	// int &
	decltype(c) c_dt = c;	// const int
	decltype(d) d_dt = d;	// cont int &

	std::cout << a_dt << " " << c_dt << std::endl;

	return(0);
}
