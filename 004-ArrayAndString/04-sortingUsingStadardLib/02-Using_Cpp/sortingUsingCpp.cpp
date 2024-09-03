#include <iostream>
#include <algorithm>

int main(void)
{
	bool compare(int, int);

	int data[] = { 32,71,12,45,26 };

	// start ptr, end ptr, func ptr
	std::sort(data, data + 5, compare); 
	
	// for assending order use only first two parameters
	// std::sort(data, data+5);

	for (int i = 0; i < 5; i++)
		std::cout << data[i] << " ";

	return(0);
}

bool compare(int numberOne, int numberTwo)
{
	return(numberOne > numberTwo);
}
