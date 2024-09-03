#include <iostream>
#include <cstring>
#include <cstdlib>

class String
{
public:
	char *str;
	size_t length;

	String(char *s): str(strdup(s)),length(std::strlen(str)) {}
	
	~String(void)
	{
		if(str)
			free(str);
		str = NULL;
	}

	String operator=(String &s)
	{
		if (this != &s)
		{
			free(str);
			str = strdup(s.str);
			length = s.length;
		}

		return(*this);
	}

	void print(void)
	{
		std::cout << "( " << str << " : " << length << " )" << std::endl;
	}
};

int main(void)
{
	String stringOne = "Football";
	String stringTwo = "Cricket";
	
	stringOne.print();
	stringTwo.print();

	stringOne = stringTwo;

	stringOne.print();

	return(0);
}
