#pragma once
#include <iostream>
#include <ctime>
#include "date.h"

char monthName[][4] = { "Jan",	"Feb",	"Mar",	"Apr",	"May",
	"Jun",	"Jul",	"Aug",	"Sep", "Oct",	"Nov", "Dec"
};
Date::Date(UINT date, UINT month, UINT year) :
	date(date),
	month((Month)month),
	year(year)
{
	std::cout << "Constructor" << std::endl;
	DateStruct.tm_year = (year - 1900);
	DateStruct.tm_mon = (month - 1);
	DateStruct.tm_mday = (date);
}

Date::~Date(void)
{
	std::cout << "Destructor" << std::endl;
}

void Date::print(void)
{
	std::cout << date << " / " << monthName[month - 1] << " / " << year << std::endl;
}

bool Date::validDate(void)
{
	if ((year % 4 == 0) && (date <= 0 && date > 29))
		return false;

	switch (month - 1)
	{
	case Date::JAN:
	case Date::MAR:
	case Date::MAY:
	case Date::JUL:
	case Date::AUG:
	case Date::OCT:
	case Date::DEC:
		if (date <= 0 || date > 31)
			return(false);
		break;

	case Date::FEB:
		if (date > 28 || date <= 0)
			return false;
		break;

	case Date::APR:
	case Date::JUN:
	case Date::SEP:
	case Date::NOV:
		if (date > 30 || date <= 0)
			return(false);
		break;
	default:
		return(false);
		break;
	}
	return(true);
}

