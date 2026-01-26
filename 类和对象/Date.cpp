#include<iostream>
using namespace std;
#include"Date.h"

//定义不需要给缺省参数
Date::Date(int year , int month , int day)

{
	_year = year;
	_month = month;
	_day = day;
}

bool Date::operator< (const Date& d)
{
	if (_year > d._year)
	{
		return true;

	}
	if (d._year == _year && d._month > _month)
	{
		return true;
	}
	if (d._year == _year && d._month == _month && d._day > _day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::operator==(const Date& d)
{
	return _year == d._year&&
	_month ==d._month&&
	_day == d._day;
}
bool Date::operator<=(const Date& d) 
{
	//要么小于要么等于都可以
	return  *this<d || *this==d;
}
//d1>d2  d1=*this d2=d

bool Date::operator>(const Date& d)
{
	return !(*this < d || *this == d);
}
//d1>=d2  d1=*this d2=d
bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}
int Date::getmonthday(int year,int month)
{
	int day_month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//闰年
	if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return day_month[month] + 1;
	}
	else
	{
		return  day_month[month];
	}
		
}

//d+day  d=*this day=day
Date&  Date::operator+=(int day)
{
	_day += day;
	while (_day>getmonthday(_year,_month))
	{
		_day -= getmonthday(_year, _month);
		_month++;
		if (_month > 12)
		{//大于12月份就归一，年份加一
			_month = 1;
			_year++;
		}
	}
	return *this;
}

