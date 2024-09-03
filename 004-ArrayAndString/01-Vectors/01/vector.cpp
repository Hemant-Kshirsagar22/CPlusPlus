#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

int main(void)
{
	vector<int> array(MAX);

	cout << endl << endl;
	cout << "Enter The No Of Elements : ";

	int count = 0;
	int sum = 0;

	cin >> count;

	cout << endl;
	
	for (int i = 0; i < count; i++)
	{
		array[i] = i;
		sum = sum + array[i];
	}

	cout << "Array Sum : " << sum << endl;

	return(0);
}
