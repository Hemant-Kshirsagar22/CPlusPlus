#include <iostream>
#include <memory>

struct Foo
{
	Foo(void)
	{
		std::cout << "Foo::Foo\n";
	}

	~Foo(void)
	{
		std::cout << "Foo::~Foo\n";
	}

	void bar(void)
	{
		std::cout << "Foo::bar\n";
	}
};

void f(const Foo &foo)
{
	std::cout << "f(const Foo&)\n";
}

int main(void)
{
	std::unique_ptr<Foo> p1 = std::make_unique<Foo>();	// (C++14) p1 owns Foo. Foo::Foo
	// std::unique_ptr<Foo> p1(new Foo);			// (C++11) p1 owns Foo
	
	if(p1) 
	{
		p1->bar();
	}

	{
		std::unique_ptr<Foo> p2(std::move(p1));
		f(*p2);	// f(const Foo&);
		p1 = std::move(p2);
		std::cout << "Destroying P2....\n";
	}

	if(p1)
	{
		p1->bar(); // Foo instance is destroyed when p1 goes out of scope 
	}
	
}

