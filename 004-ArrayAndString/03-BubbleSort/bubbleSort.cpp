#include <iostream>

int main(void)
{
	int data[] = { 32, 71, 12, 45, 26 };
	int n = 5;
	int temp;

	for (int step = 0; step < n - 1; ++step)
	{
		for (int i = 0; i < n - step - 1; ++i)
		{
			if (data[i] > data[i + 1])
			{
				temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		std::cout << data[i] << " ";

	return(0);
}
