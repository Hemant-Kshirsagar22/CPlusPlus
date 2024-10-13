#include <iostream>
#include <string>

using namespace std;

enum E_TYPE{ENGINEER,MANAGER,DIRECTOR};

class Engineer
{
protected:
	string name_;
	E_TYPE type_;

public:
	Engineer(const string& name,E_TYPE e = ENGINEER) : name_(name), type_(e) {}
	E_TYPE getType(void) 
	{
		return(type_);
	};

	void processSalary(void)
	{
		cout << name_ << ": Process Salary for Engineer" << endl;
	}
};

class Manager : public Engineer
{
	Engineer *reports_[10];

public:
	Manager(const string &name,E_TYPE e = MANAGER) : Engineer(name, e) {}
	void processSalary(void)
	{
		cout << name_ << ": Process Salary for Manager" << endl;
	}
};

class Director : public Manager
{
	Manager *reports_[10];
public:
	Director(const string &name) : Manager(name, DIRECTOR) {}
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
		E_TYPE t = staff[i]->getType();
		if (t == ENGINEER)
			staff[i]->processSalary()
			;
		else if (t == MANAGER)
			((Manager *)staff[i])->processSalary()
			;
		else if (t == DIRECTOR)
			((Director *)staff[i])->processSalary()
			;
		else cout << "Invalid Staff Type" << endl;
	}

	return(0);
}
