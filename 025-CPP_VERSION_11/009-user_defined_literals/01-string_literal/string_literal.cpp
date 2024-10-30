#include <iostream>
#include <string>

using namespace std;

std::string operator"" _s(const char *p, size_t n)
{
	return string(p,n);
}

template<class T>
void f(const T& a)
{
	cout << a << endl;
}

int main(void)
{
	f("Hello"); // pass pointer to char * = > const char (&)[6]
	f("Hello"_s); // pass (5-character) std::string object
	f("Hello\n"_s); // pass (6-character) std::string object

	return(0);
}

