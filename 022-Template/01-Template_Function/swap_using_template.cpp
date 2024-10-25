#include <iostream>
#include <string>

using namespace std;

template<class T>
void Swap(T& one, T& two)
{
	T temp;
	temp = one;
	one = two;
	two = temp;
}

int main(void)
{
	int numberOne = 10;
	int numberTwo = 20;
	cout << "Before swaping" << endl;
	cout << "numberOne = " << numberOne << ", numberTwo = " << numberTwo << endl;

	swap(numberOne,numberTwo);

	cout << "After Swaping" << endl;
	cout << "numberOne = " << numberOne << ", numberTwo = " << numberTwo << endl;
	
	string stringOne = "Hello";
	string stringTwo = "Hemant";
 
	cout << "Before Swaping" << endl; 
	cout << "stringOne = " << stringOne  << ", stringTwo = " << stringTwo << endl;

	swap(stringOne,stringTwo);
	
	cout << "After Swaping" << endl;
	cout << "stringOne = " << stringOne << ", stringTwo = " << stringTwo << endl;

	return(0);	
}	

