#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
	std::ifstream myFile("abc.txt");

	std::string line;

	if(myFile.is_open())
	{
		while(std::getline(myFile,line))
		{
			std::cout << line << "\n";
		}
		
		myFile.close();
	}
	else
	{
		std::cout << "Unable To Open File !!!\n";
	}

	return(0);
}

