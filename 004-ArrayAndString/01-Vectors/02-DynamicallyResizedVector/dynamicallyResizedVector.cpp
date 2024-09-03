#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	cout << "Enter The No Of Elements : ";
	int count, sum = 0;
	cin >> count;

	vector<int> array; // default size
	array.resize(count); // set size

	for (int i = 0; i < array.size(); i++)
	{
		array[i] = i;
		sum += array[i];
	}

	cout << "Array Sum : " << sum << endl;

	return(0);
}
