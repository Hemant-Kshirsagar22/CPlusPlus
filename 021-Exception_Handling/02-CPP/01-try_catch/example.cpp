#include <iostream>
#include <exception>

using namespace std;

class Exception : public exception
{

};
int main(void)
{
	void g(void);
	try // In this block we write statements that can/will throw exceptions
	{
		cout << "g() called\n";
		g();
		cout << "g() returned\n";
	}
	catch(Exception&) // in this block we catch exception and handle the exception
	{
		cout << "g() failed\n";
	}
	catch(...) // this block must be the last catch block because it catesh all exception, if no matching handler found in the current scope,the search continues to find a matching handler in a dynamically surrounding try block
	{
		cout << "It catches all exceptions";
	}

	// if eventually no handler is found terminate() is called

	return(0);
}

void g(void)
{
	bool error = false; // when we make error true then it will throw exception class object and it will catch by the catch block

	printf("g() started\n");

	if(error)
		throw Exception();

	cout << "g() endend\n";

	return;
}


