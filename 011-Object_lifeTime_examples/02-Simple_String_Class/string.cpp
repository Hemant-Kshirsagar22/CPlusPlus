#include <iostream>
#include <cstring>
#include <cstdlib>

class String
{
private:
	char *string;
	size_t length; // here if we declare the length first then it will initializes first and gives error to the constructor initializeation(Line 14)

public:
	String(char *s) :
		string(strdup(s)),
		length(std::strlen(string)) // line 14
	{
		std::cout << "contructor" << std::endl;
	}

	void print(void)
	{
		std::cout << "[ " << string << "\tlength : " << length << "]\n";
	}

	size_t len(void)
	{
		return(length);
	}

	~String(void)
	{
		std::cout << "distrustor" << std::endl;
		
		if (string)
		{
			free(string);
			string = NULL;
		}
	}
};

int main(void)
{
	String string = "Hemant\0";
	string.print();

	return(0);
}