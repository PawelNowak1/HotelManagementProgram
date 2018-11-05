#pragma once

struct Date
{
public:
	int day;
	int month;
	int year;
	Date(int d, int m, int y);
	Date();
	void initDate();
	static bool areDatesColliding(Date begin1, Date end1, Date begin2, Date end2);
};