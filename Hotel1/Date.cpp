#include "stdafx.h"
#include "Date.h"
#include <iostream>

Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}

Date::Date()
{

}

void Date::initDate()
{
	std::cout << "\nDzien: ";
	std::cin >> day;
	std::cout << "\nMiesiac: ";
	std::cin >> month;
	std::cout << "\nRok: ";
	std::cin >> year;
}

bool isDateOlder(Date date1, Date date2) // return true if date1 is older
{
	if (date1.year > date2.year)
		return true;
	if(date1.year < date2.year)
		return false;
	if (date1.month > date2.month)
		return true;
	if (date1.month < date2.month)
		return false;
	if (date1.day > date2.day)
		return true;
}
bool Date::areDatesColliding(Date begin1, Date end1, Date begin2, Date end2)
{
	//(StartA <= EndB) and (EndA >= StartB)
	if (isDateOlder(end2, begin1) && isDateOlder(end1, begin2))
			return true;
	return false;
}
