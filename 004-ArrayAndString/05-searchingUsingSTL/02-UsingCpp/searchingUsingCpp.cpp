#include <iostream>
#include <algorithm>

int main(void)
{
	int data[] = { 1,2,3,4,5 };
	int key = 3;
	
	if (std::binary_search(data, data + 5, key))
		std::cout << "found !!!\n";
	else
		std::cout << "Not Found !!!\n";

	return(0);
}
