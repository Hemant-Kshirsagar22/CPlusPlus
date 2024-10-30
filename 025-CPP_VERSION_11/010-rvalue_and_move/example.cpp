#include <iostream>

class A
{
	public:
		A(void)
		{
			std::cout << "Default Constructor" << std::endl;
		}

		A(const A&)
		{
			std::cout << "Copy Constructor" << std::endl;
		}

		A(A&&) noexcept
		{
			std::cout << "Move Constructor" << std::endl;
		}

		A& operator=(const A&)
		{
			std::cout << "Copy =" << std::endl;
			return (*this);
		}

		A& operator=(const A&&) noexcept
		{
			std::cout << "Move =" << std::endl;
			return *this;
		}

		friend A operator+(const A &a, const A &b)
		{
			A t;
			return(t);
		}
};
int main(void)
{
	A a;
	A b = a;
	A c = a + b;

	A d = std::move(a);
	b = a;
	c = a + b;
}

