#include <iostream>
#include <string>

using namespace std;

class Engineer
{
protected:
	string name_;
public:
	Engineer(const string& name) : name_(name) {}
	
	virtual void processSalary(void)
	{
		cout << name_ << ": Process Salary for Engineer" << endl;
	}
};

class Manager : public Engineer
{
	Engineer *reports_[10];

public:
	Manager(const string &name) : Engineer(name) {}
	void processSalary(void)
	{
		cout << name_ << ": Process Salary for Manager" << endl;
	}
};

class Director : public Manager
{
	Manager *reports_[10];
public:
	Director(const string &name) : Manager(name) {}
	void processSalary(void)
	{
		cout << name_ << ": Process Salary for Director" << endl;
	}
};

int main(void)
{
	Engineer engineerOne("Hemant");
	Engineer engineerTwo("Rohit");
	Engineer engineerThree("Shambhu");

	Manager managerOne("Kamala");
	Manager managerTwo("Rajib");

	Director director("Ranjana");

	Engineer *staff[] = { &engineerOne,&engineerTwo,&engineerThree,&managerOne,&managerTwo,&director };

	for (int i = 0; i < sizeof(staff) / sizeof(Engineer *); ++i)
	{
		staff[i]->processSalary();
	}

	return(0);
}
