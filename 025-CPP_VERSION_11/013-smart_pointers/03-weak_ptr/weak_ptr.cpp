#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void f(void)
{
	if(auto sharedPtr = gw.lock()) // has to be copied into a shared_ptr before usage
	{
		std::cout << *sharedPtr << "\n";
	}
	else
	{
		std::cout << "gw is expired\n";
	}
}


int main(void)
{
	{
		auto sp = std::make_shared<int>(50);
		gw = sp;
		f();
	}

	f();

	return(0);
}

