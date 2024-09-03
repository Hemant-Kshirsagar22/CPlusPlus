#include <iostream>
#include <cstring>

typedef struct _String
{
	char *str;
}String;

int main(void)
{
	String operator+(const String &, const String &);

	String fName;
	String lName;
	String fullName;

	fName.str = strdup("Hemant ");
	lName.str = strdup("Kshirsagar");

	fullName = fName + lName;
	std::cout << "First Name : " << fName.str << std::endl;
	std::cout << "Last Name  : " << lName.str << std::endl;
	std::cout << "Full Name  : " << fullName.str << std::endl;

	return(0);
}

String operator+(const String &firstName, const String &lastName)
{
	String fullName;
	fullName.str = (char *)malloc(strlen(firstName.str) + strlen(lastName.str) + 1); // Allocation
	strcpy(fullName.str, firstName.str);
	strcat(fullName.str, lastName.str);
	return(fullName);
}
