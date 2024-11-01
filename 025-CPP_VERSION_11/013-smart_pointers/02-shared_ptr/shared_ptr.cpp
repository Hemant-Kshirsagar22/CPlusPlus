#include <iostream>
#include <memory>

int main(void)
{
	std::shared_ptr<int> p1 = std::make_shared<int>();	// creating through make_shared
	
	*p1 = 78;	// set a value for the managed object
	std::cout << "p1 = " << *p1 << std::endl; // access the value from managed object p1 = 78
	std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;

	std::shared_ptr<int> p2(p1);	// second shared_ptr points to same pointer Referenece count = 2
	std::cout << "p2 Reference Count = " << p2.use_count() << std::endl;	// p2 RC = 2
	std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;	// p1 RC = 2 

	if(p1 == p2)
	{
		std::cout << "Same Objects\n";
	}

	std::cout << "Reset P1" << std::endl;

	p1.reset(); // reset the shared_ptr - it will not point to any object
	std::cout << "p1 RC = " << p1.use_count() << std::endl; // RC = 0

	p1.reset(new int(11)); // reset the shared_ptr with new Pointer
	std::cout << "p1 RC = " << p1.use_count() << std::endl; // RC = 1

	p1 = nullptr; // Assign nullptr to de-attach managed object
	std::cout << "p1 RC = " << p1.use_count() << std::endl; // RC = 0

	if(!p1)
	{
		std::cout << "p1 is NULL" << std::endl; // test pointer is null or not
	}

	return(0);
}

