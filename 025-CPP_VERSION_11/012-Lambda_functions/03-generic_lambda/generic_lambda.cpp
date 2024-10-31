#include <iostream>

// C++ 11 lambda's - separate lambda for every type return type is optional
auto add_i = [](int a, int b)
{
	return(a + b);
};

auto add_d = [](double a, double b)
{
	return(a + b);
};

auto add_s = [](std::string a, std::string b)
{
	return(a + b);
};

// c++ 11 templatized lambda - one lambda for multiple types. return type is optioal

template<typename T>
auto add_t = [](T a,T b)
{
	return(a + b);
};

// c++ 14 generic lambda return type cannot be specified
auto add = [](auto a, auto b) 
{
	return(a + b);
};

int main(void)
{
	// different name of each lamba for each type 
	std::cout << add_i(10, 20);
	std::cout << add_d(2.6, 1.3);
	std::cout << add_s("Hemant ","Kshirsagar") << std::endl;

	// smae name of the lambda for all types. type must be specified : no inference
	std::cout << add_t<int>(3,5);
	std::cout << add_t<double>(3.7,2.3);
	std::cout << add_t<std::string>("Good ","day") << std::endl;

	// same name of the lambda for all types and no type need to be specified 
	std::cout << add(3,4);
	std::cout << add(3.7,2.3);
	std::cout << add(std::string("Hello "), std::string("World !!!")) << std::endl;
	return(0);
}

