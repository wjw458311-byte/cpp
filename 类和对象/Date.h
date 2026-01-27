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
	/*Date& operator=(const Date& d)
			{
				_year = d._year;
				_month = d._month;
				_day = d._day;
				return *this;
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
	Date& operator-=(int day);
	int operator-(const Date &d);
private:
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
	
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d);

istream& operator>>(istream& in, Date& d);
