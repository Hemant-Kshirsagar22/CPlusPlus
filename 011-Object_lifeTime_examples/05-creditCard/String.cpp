#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "String.h"

String::String(char *s) :
	string(strdup(s)),
	length(std::strlen(string)) // line 14
{
	std::cout << "String contructor" << std::endl;
}

void String::print(void)
{
	std::cout << "[ " << string << "\tlength : " << length << "]\n";
}

size_t String::len(void)
{
	return(length);
}

String::~String(void)
{
	std::cout << "String distrustor" << std::endl;

	if (string)
	{
		free(string);
		string = NULL;
	}
}
