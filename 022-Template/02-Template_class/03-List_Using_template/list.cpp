#include <iostream>
#include "list.h"

int main(void)
{
	List<int> list;
	int choice = 0;
	int number = 0;
	while(true)
	{
		std::cout << "\t\tMENU" << std::endl;
		std::cout << "01-PUT DATA INTO LIST\n02-PRINT LIST\n03-PRINT LENGTH\n04-FIND ELEMENT\n05-EXIT\n\nENTER YOUR CHOICE : ";
		std::cin >> choice;

		switch(choice)
		{
			case 1:
				std::cout << "\nENTER THE NUMBER FOR PUTTING INTO LIST: ";
				std::cin >> number;

				list.put(number);
				std::cout << "\n\nNUMBER INSERTED SUCCESSFULLY !!!\n" << std::endl;
				break;

			case 2:
				cout << "\n";
				list.print();
				cout << endl;
				break;

			case 3:
				std::cout << "\nLENGTH OF LIST IS : " << list.length() << std::endl << std::endl;
				break;

			case 4:
				std::cout << "\nENTER THE ELEMNT TO FIND : ";
				std::cin >> number;

				if(list.find(number))
				{
					std::cout << "\n";
					std::cout << number << " IS PRESENT IN LIST\n" << std::endl;
				}
				else
				{
					std::cout << "\n";
					std::cout << number << " IS NOT PRESENT IN LIST\n" << std::endl;
				}

				break;

			case 5:
				return(0);
				break;

		}
	}
}
