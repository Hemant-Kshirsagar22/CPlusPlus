#include <iostream>

class PrintJobs
{
	int nPages; // Pages of current jobs
	static int nTrayPages; // number of pages in the tray
	static int nJobs; // number of printer jobs executing
public :
	PrintJobs(int nP) : nPages(nP)
	{
		nJobs++;
		std::cout << "Printing " << nP << " Pages" << std::endl;
		nTrayPages = nTrayPages - nP;
	}

	~PrintJobs(void)
	{
		nJobs--;
	}

	static int getJobs(void)
	{
		return(nJobs);
	}

	static int checkPages(void)
	{
		return(nTrayPages);
	}

	static void loadPages(int nP)
	{
		nTrayPages = nTrayPages + nP;
	}
};

int PrintJobs::nTrayPages = 500; // defination and initialization of number of pages in tray
int PrintJobs::nJobs = 0; // defination and initialization of number of jobs to start with

int main(void)
{
	std::cout << "Jobs : " << PrintJobs::getJobs() << std::endl;
	std::cout << "Pages In Tray : " << PrintJobs::checkPages() << std::endl;

	PrintJobs jobOne(10);
	
	std::cout << "Jobs : " << PrintJobs::getJobs() << std::endl;
	std::cout << "Pages In Tray : " << PrintJobs::checkPages() << std::endl;

	{
		PrintJobs jobOne(30), jobTwo(20); // different jobone in block scope
		
		std::cout << "Jobs : " << PrintJobs::getJobs() << std::endl;
		std::cout << "Pages In Tray : " << PrintJobs::checkPages() << std::endl;

		PrintJobs::loadPages(100);
	}


	std::cout << "Jobs : " << PrintJobs::getJobs() << std::endl;
	std::cout << "Pages In Tray : " << PrintJobs::checkPages() << std::endl;

	return(0);
}
