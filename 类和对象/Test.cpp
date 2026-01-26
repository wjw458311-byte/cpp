#include<iostream>
using namespace std;
//class Date
//{
//public:
//	Date(int year=2000, int month=12, int day=22)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	/*Date(const Date& d)
//	{
//		_year = d._day;
//		_month = d._month;
//		_day = d._day;
//	}*/
//	
////private:
//	int _year;
//	int _month;
//	int _day;
//};
typedef int stacktype;
class Stack
{
public:

	
	Stack(int capacity=4)
	{
		_a = (stacktype*)malloc(sizeof(stacktype) * 4);
		if (_a == nullptr)
		{
			perror("malloc  failure!!!");
			return;
		}
		_capacity = 4;
		_size = 0;
	}
	//深拷贝
	Stack(Stack& st)
	{
		_a = (stacktype*)malloc(sizeof(stacktype) * 4);
		if (_a == nullptr)
		{
			perror("malloc  failure!!!");
			return;
		}
		memcpy(_a,st._a,sizeof(int)*st._size);
		_capacity = st._capacity;
		_size = st._size;
	}
	
	//析构函数
	~Stack()
	{
		if (_a)
		{
			free(_a);
			_a = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	stacktype* _a;
	int _capacity;
	int _size;

};
//void func1(Date& d)
//	{
//
//	}
//void func2(int)
//	{
//
//	}
//拷贝构造
//int main()
//{
//	
//	Date d1(2024,2,4);
//	Date d2(d1);
//
//	func1(d1);
//	func2(10);
//
//
//	//必须深拷贝，不能值拷贝
//	Stack st1;
//	Stack st2(st1);
//	return 0;
//
//}

//void func(Stack& st )
//{
//	
//}
//Stack& func2()
//{
//	static  Stack st;
//	return st;
//
//}

//不能引用局部返回
//Stack& func3()
//{
//	Stack st;
//	return st;
//}
//int main()
//{
//	Date d1;
//	func1(d1);
//	Stack st1;
//	func(st1);
//	//func3();
//	//Stack ret = func3();
//	return 0;
//}

//bool Less(Date&d1,Date&d2)
//{
//	if (d1._year < d2._year)
//	{
//		return true;
//
//	}
//	if (d1._year == d2._year && d1._month < d2._month)
//	{
//		return true;
//	}
//	if (d1._year == d2._year && d1._month == d2._month&&d1._day<d1._day)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}




//bool operator< ( Date& d1, Date& d2)
//{
//	if (d1._year < d2._year)
//	{
//		return true;
//
//	}
//	if (d1._year == d2._year && d1._month < d2._month)
//	{
//		return true;
//	}
//	if (d1._year == d2._year && d1._month == d2._month && d1._day < d1._day)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
//bool operator> (Date& d1, Date& d2)
//{
//	if (d1._year > d2._year)
//	{
//		return true;
//
//	}
//	if (d1._year == d2._year && d1._month > d2._month)
//	{
//		return true;
//	}
//	if (d1._year == d2._year && d1._month == d2._month && d1._day > d1._day)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//int main()
//{
//	Date d1(2026, 2, 12);
//	Date d2(2025, 1, 25);
//	//cout <<Less(d1, d2) << endl;
//	cout << (d1>d2) << endl;
//	cout << (d1<d2) << endl;
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 2000, int month = 12, int day = 22)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		cout << "1" << endl;
//		_year = d._day;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator> (const Date& d1)
//	{
//		if (_year > d1._year)
//		{
//			return true;
//
//		}
//		if (d1._year == _year && d1._month >_month)
//		{
//			return true;
//		}
//		if (d1._year == _year && d1._month == _month && d1._day > _day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//	private:
//	int _year;
//	int _month;
//	int _day;
//};
////int main()
////{
////	Date d1(2026, 2, 12);
////	Date d2(2025, 1, 25);
////	//cout <<Less(d1, d2) << endl;
////	d1 > d2;
////	
////	return 0;
////}
//
//int main()
//{
//	Date d1(2026, 2, 12);
//	Date d2(2025, 1, 25);
//	d1 = d2;
//	Date d3(d1);
//	Date d4, d5;
//	d4=d5 = d2;
//}