#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream myFile;

	myFile.open("abc.txt");
	myFile << "Writing this to a file.\nMy name is hemant\nHello World !!!\n";
	myFile.close();
}

