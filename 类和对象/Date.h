#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2000, int month =12, int day=12);
	//拷贝构造不用
	/*Date(const Date& d)
	{
		cout << "1" << endl;
		_year = d._day;
		_month = d._month;
		_day = d._day;
	}*/
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator< (const Date& d);
	bool operator==(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	int getmonthday(int year,int month);
	Date& operator+=(int day);

private:
	int _year;
	int _month;
	int _day;
};
