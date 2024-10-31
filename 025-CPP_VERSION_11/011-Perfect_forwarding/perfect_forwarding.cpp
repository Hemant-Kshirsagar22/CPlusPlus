#include <iostream>

class Data
{
	int numberOne;

	public:
	Data(void) : numberOne(0) {}
};

void g(const int&)
{
	std::cout << "int& in g" << std::endl;
}

void g(const int&&)
{
	std::cout << "int&& in g" << std::endl;
}

void h(const Data&)
{
	std::cout << "Data& in h" << std::endl;
}

void h(const Data&&)
{
	std::cout << "Data&& in h" << std::endl;
}

template<typename T1, typename T2>
void f(T1&& p1, T2&& p2)
{
	g(std::forward<T1>(p1)); // here std::forward is used for prefect forwarding the parameters of templates , If we dont use std::forward then the g(const int&) is always called whether we pass rvalue parameter or lvalue parameter
	h(std::forward<T2>(p2)); // same as above
}

int main(void)
{
	int numberOne { 0 };
	Data d;
	f(numberOne, d);
	f(std::move(numberOne), d);
	f(numberOne, std::move(d));
	f(std::move(numberOne), std::move(d));

	return(0);
}

