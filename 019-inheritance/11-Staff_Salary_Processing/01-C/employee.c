#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum E_TYPE {ENGINEER,MANAGER} E_TYPE; // tag for type of staff

typedef struct Engineer
{
	char *name_;
}Engineer;

Engineer *initEngineer(const char *name)
{
	Engineer *e = (Engineer *)malloc(sizeof(Engineer));
	e->name_ = strdup(name);
	return(e);
}

void ProcessSalaryEngineer(Engineer *e)
{
	printf("%s : Process Salary for Engineer\n", e->name_);
}

typedef struct Manager
{
	char *name_;
	Engineer *reports_[10];
} Manager;

Manager *initManager(const char *name)
{
	Manager *m = (Manager *)malloc(sizeof(Manager));
	m->name_ = strdup(name);
	return(m);
}

void processSalaryMangaer(Manager *m)
{
	printf("%s : Process Salary for Manager\n", m->name_);
}

typedef struct Staff
{
	E_TYPE type_;
	union 
	{
		Engineer *pE;
		Manager *pM;
	};
} Staff;

int main(void)
{
	Staff allStaff[5];

	allStaff[0].type_ = ENGINEER;
	allStaff[0].pE = initEngineer("Rohit");

	allStaff[1].type_ = MANAGER;
	allStaff[1].pM = initManager("Kamala");

	allStaff[2].type_ = MANAGER;
	allStaff[2].pM = initManager("Hemant");
	
	allStaff[3].type_ = ENGINEER;
	allStaff[3].pE = initEngineer("Kavita");

	allStaff[4].type_ = ENGINEER;
	allStaff[4].pE = initEngineer("Shambhu");

	for (int i = 0; i < 5; i++)
	{
		E_TYPE t = allStaff[i].type_;

		if (t == ENGINEER)
		{
			ProcessSalaryEngineer(allStaff[i].pE);
		}
		else if (t == MANAGER)
		{
			processSalaryMangaer(allStaff[i].pM);
		}
		else
		{
			printf("Invalid Staff Type\n");
		}
	}

	return(0);
}
