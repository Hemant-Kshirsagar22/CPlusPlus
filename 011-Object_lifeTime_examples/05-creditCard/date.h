#pragma once
typedef unsigned int UINT;


class Date
{
private:
	enum Month {
		JAN = 1, FEB, MAR, APR, MAY,
		JUN, JUL, AUG, SEP, OCT, NOV, DEC
	};
	UINT date;
	Month month;
	UINT year;
	std::tm DateStruct;
public:
	Date(UINT date, UINT month, UINT year);
	~Date(void);
	void print(void);
	bool validDate(void);
};
