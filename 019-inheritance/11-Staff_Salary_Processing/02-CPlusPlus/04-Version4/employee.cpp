#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
protected:
	string name_;
	vector<Employee *>reports_;
public:
	virtual void processSalary() = 0;
	virtual ~Employee() {}
	static vector<Employee *> staffs;
	void AddStaff(Employee *e)
	{
		staffs.push_back(e);
	}
};
class Engineer : public Employee
{
public:
	Engineer(const string& name)
	{
		name_ = name;
		AddStaff(this);
	}
	
	virtual void processSalary(void)
	{
		cout << name_ << ": Process Salary for Engineer" << endl;
	}
};

class Manager : public Engineer
{
public:
	Manager(const string &name) : Engineer(name) {}
	void processSalary(void)
	{
		cout << name_ << ": Process Salary for Manager" << endl;
	}
};

class Director : public Manager
{
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
		AddStaff(this);
	}

	void processSalary(void)
	{
		cout << name_ << ": Process Salary for Sales Executive" << endl;
	}
};
vector<Employee *> Employee::staffs;

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

	vector<Employee *>::const_iterator it;

	for (it = Employee::staffs.begin(); it < Employee::staffs.end(); ++it)
	{
		(*it)->processSalary();
	}

	return(0);
}
