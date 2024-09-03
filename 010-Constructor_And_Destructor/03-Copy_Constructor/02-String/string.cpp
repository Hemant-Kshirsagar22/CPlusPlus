#include <iostream>
#include <cstring>
#include <cstdlib>

class String {
public:
	char *string;
	size_t length;

	String(char *string) : string(strdup(string)),length(strlen(string)) {}
	String(const String &str):
		string(str.string),
		length(str.length)
	{}
	~String(void)
	{
		if (string)
		{
			free(string);
			string = NULL;
		}
	}
	
	String &operator=(String &str)
	{
		if (this != &str)				// Check if the source and destination are same
		{
			free(string);				 // Release existing memory
			string = strdup(str.string); // Perform deep copy
			length = str.length;		 // Copy data member of built-in type 
		}

		return(*this);
	}

	void print(void)
	{
		std::cout << "(" << string << " : " << length << ")\n";
	}
};

int main(void)
{
	String stringOne = "Football\0";
	String stringTwo = "Cricket\0";
	String stringThree = stringTwo;
	stringOne.print();
	stringTwo.print();
	stringOne = stringOne;
	stringOne.print();
	stringThree.print();

	return(0);
}
