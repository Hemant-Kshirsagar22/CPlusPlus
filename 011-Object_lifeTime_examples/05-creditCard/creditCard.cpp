#include <iostream>
#include "String.h"
#include "date.h"

using namespace std;

class Name
{
	String firstName;
	String lastName;
public:
	Name(char *fName, char *lName) :
		firstName(fName), lastName(lName)
	{
		cout << "Name constructor";
		print();
		cout << endl;
	}

	~Name(void)
	{
		cout << "Name Destructor";
		print();
		cout << endl;
	}

	void print(void)
	{
		firstName.print();
		cout << " ";
		lastName.print();
	}
};

class Address
{
	unsigned int houseNo;
	String street;
	String city;
	String pin;

public:
	Address(unsigned int hn, char *sn, char *cn, char *pin) :
		houseNo(hn),
		street(sn),
		city(cn),
		pin(pin)
	{
		cout << "Address constructor" << endl;
	}

	~Address(void)
	{
		cout << "Address Destructor" << endl;
	}

	void print(void)
	{
		cout << houseNo << " ";
		street.print();
		city.print();
		pin.print();
	}
};

class CreditCard
{
	char cardNumber[17];
	Name holder;
	Address address;
	Date issueDate;
	Date expiryDate;
	UINT cvv;

public:
	CreditCard(char *cNumber, char *fName, char *lName, unsigned int houseNo, char *street,
		char *cityName, char *pin, UINT issueMonth, UINT issueYear, UINT expiryMonth,
		UINT expiryYear, UINT cvv) :
		holder(fName, lName),
		address(houseNo, street, cityName, pin),
		issueDate(1, issueMonth, issueYear),
		expiryDate(1, expiryMonth, expiryYear),
		cvv(cvv)
	{
		strcpy(cardNumber, cNumber);
		cout << "CreditCard Constructor\n";
	}

	~CreditCard(void)
	{
		cout << "CreditCard Destrouctor\n";
	}

	void print(void)
	{
		cout << cardNumber << "\n";
		holder.print();
		address.print();
		issueDate.print();
		expiryDate.print();
		cout << "CVV : " << cvv << endl;
	}

};
int main(void)
{
	/*Name name(strdup("Hemant"), strdup("Kshirsagar"));
	Address address(666, strdup("Shimpi Ali"), strdup("pune"), strdup("411011"));*/

	CreditCard card("1234567890123456", "Hemant", "Kshirsagar", 666, "Shimpi ALi", "Pune", "411011", 7, 2024, 7, 2027, 986);
	cout << endl << endl;
	card.print();
	cout << endl << endl;
	return(0);
}
