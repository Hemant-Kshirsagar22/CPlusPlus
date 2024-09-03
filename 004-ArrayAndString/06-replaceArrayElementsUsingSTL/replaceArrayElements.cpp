#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int data[] = { 1,2,3,4,5 };

	// first , last , old val, new val
	std::replace(data, data + 5, 3, 2);

	for (int i = 0; i < 5; i++)
		std::cout << data[i] << " ";

	return(0);
}
