#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string stringOne = "\n\nHello ";
	string stringTwo = "world !!!\n\n";

	string stringThree = stringOne + stringTwo;

	cout << stringThree;

	return(0);
}
