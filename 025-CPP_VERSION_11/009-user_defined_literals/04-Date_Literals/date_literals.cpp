#include <iostream>
#include <cstring>

using namespace std;

class Date
{
	int date;
	int month;
	int year;

	public:
	Date(int d = 1, int m = 1, int y = 0) : date(d),month(m),year(y) {}
	friend ostream& operator<<(ostream& os, const Date& d)
	{
		os << d.date << "/" << d.month << "/" << d.year;

		return(os);
	}
};

Date operator"" _ad(const char *s,size_t)
{
	// representation of date as "dd/mm/yyyy" fromat
	// parsing s into dd, mm, year as int
	char *str = strdup(s); // copy needed as s is const char* - strtok cannot work on s
	char *date_str = strtok(str,"/");
	int date = atoi(date_str);

	date_str = strtok(NULL,"/");
	int month = atoi(date_str);

	date_str = strtok(NULL,"/");
	int year = atoi(date_str);

	free(str);

	return(Date{date,month,year});
}

int main(void)
{
	auto myDate = "08/02/2022"_ad;
	cout << myDate << endl;

	return(0);
}

