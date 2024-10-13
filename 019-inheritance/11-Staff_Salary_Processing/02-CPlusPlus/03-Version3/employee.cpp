#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
	string name_;
public:
	virtual void processSalary() = 0;
	virtual ~Employee() {}
};
class Engineer : public Employee
{
public:
	Engineer(const string& name)
	{
		name_ = name;
	}
	
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

class SalesExecutive : public Employee
{
public:
	SalesExecutive(const string &name)
	{
		name_ = name;
	}

	void processSalary(void)
	{
		cout << name_ << ": Process Salary for Sales Executive" << endl;
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

	SalesExecutive sOne("Hari");
	SalesExecutive sTwo("Bishnu");

	Employee *staff[] = { &engineerOne,&engineerTwo,&engineerThree,&managerOne,&sOne,&managerTwo,&director, &sTwo };

	for (int i = 0; i < sizeof(staff) / sizeof(Engineer *); ++i)
	{
		staff[i]->processSalary();
	}

	return(0);
}
