#include<iostream>
using namespace std;
//class Date
//{
//public:
//	Date* operator&()
//	{
//		return this;
//	}
//	const Date* operator&()const
//	{
//		return this;
//	}
//private:
//	int _year=1; // 年
//	int _month=1; // 月
//	int _day=2; // 日
//};
//int main()
//{
//	Date d1;
//	const Date d2;
//	cout << &d1 << endl;
//	cout <<& d2 << endl;
//
//	return 0;
//
//}



//函数体赋值
//class A
//{
//	//public:
//	//	Date(int year, int month, int day)
//	//		
//	//	{	
//	//			_year = year;
//	//			_month = month;	
//	//			_day = day;
//	//	}
//		
//	//初始化列表，对象成员定义的位置
//public:
//	A(int a=2)
//		:_a(a)
//	{}
//private:
//	int _a;
//
//};
//class B
//{
//public:
//	B(int ref, int n)
//		:_ref(ref)
//		, _n(n)
//		,x(3)
//	{}
//private:
//	//声明
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//	int x;//内置类型不做处理
//};
//
//int main()
//{
//	B b1(1, 1);
//}

//class A
//{
//
//	//初始化列表，对象成员定义的位置
//public:
//	A(int a=3 )
//		:_a(a)
//	{
//	}
//private:
//	int _a;
//
//};
//class B
//{
//public:
//	B(int& ref, int n)
//		:_ref(ref)
//		, _n(n)
//		, x(3)
//		,_aobj(4)
//	{
//	}
//private:
//	//声明
//	A _aobj; // 没有默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//	int x;//内置类型不做处理
//};
//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		} _size = 0;
//		_capacity = capacity;
//	}
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//class Queue
//{
//public:
//	Queue()
//	{}
//	Queue(int x)
//		:_pushst(x)
//		, _popst(x)
//	{ }
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//int main()
//{
//	int n = 10;
//	//B b1(n, 1);
//	Queue q1;
//	Queue q2(200);
//	
//}


//成员变量在类中声明次序就是其在初始化列表中的初始化顺序，
//class A
//
//{
//
//public:
//		A(int a)
//		: _a1(a)
//		, _a2(_a1)
//	{}
//		void Print() {
//			cout << _a1 << " " << _a2 << endl;
//	}
//private:
//		int _a2;
//		int _a1;
//};
//int main() 
//{
//		A aa(1);
//		aa.Print();
//}


//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{ 
//		cout << "A(int a)" << endl;
//	}
//	 A(const A&a)
//		:_a(a._a)
//	{
//		cout << "A(const A&a)" << endl;
//
//	}
//
//private:
//	int _a;
//
//};
//
//int main()
//{
//	A a1(1);
//	const A& a2 = 2;
//}


class A
{
public:
		A() { ++_scount; }
		A(const A & t) { ++_scount; }
		~A() { --_scount; }
		static int GetACount() { return _scount; }
private:
		static int _scount;
};

int A::_scount = 0;
void TestA()

{
		cout << A::GetACount() << endl;
		A a1, a2;
		A a3(a1);
		cout << A::GetACount() << endl;
}
int main()
{
	TestA();
}