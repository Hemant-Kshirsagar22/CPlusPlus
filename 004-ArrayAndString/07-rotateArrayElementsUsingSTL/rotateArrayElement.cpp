#include <iostream>
#include <algorithm>

int main(void)
{
	int data[] = { 1,2,3,4,5 };
	//			start , last , where you want to put rotated elements
	std::rotate(data,data+3,data+5);

	for (int i = 0; i < 5; i++)
		std::cout << data[i] << " ";

	return(0);
}