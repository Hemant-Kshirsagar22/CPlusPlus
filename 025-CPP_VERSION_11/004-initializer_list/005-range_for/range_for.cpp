#include <iostream>
#include <vector>
#include <map>

int main(void)
{
	std::vector<int> vectorOne = {1,2,3,4,5,6,7,8,9,10};
	
	// for(auto& i : vectorOne)
	for(std::vector<int>::value_type i : vectorOne)
	{
		std::cout << i << " ";
	}

	std::cout << "\n" << std::endl;

	// the initializer may be a braced-init-list
	for(int n : {0,1,2,3,4,5})
		std::cout << n << " ";
	std::cout << "\n" << std::endl;

	int arrayOne[] = {0,1,2,3,4,5};
	for(int n : arrayOne)
		std::cout << n << " ";
	std::cout << "\n" << std::endl;

	std::string str = "Hemant";
	for(char c : str)
		std::cout << c << " ";
	std::cout << "\n" << std::endl;

	std::map <int,int> MAP({{1,1}, {2,4}, {4,5}});

	for(auto i : MAP)
	{
		std::cout << " " << i.first << ", " << i.second << std::endl;
	}
	return(0);
}

