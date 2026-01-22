#include<iostream>

using std::cout;
using std::endl;




//inline int sub(int a, int b)
//{
//	return (a * b) * 20;
//}

#include"test.h"
//int main()
//{
//	for (int i = 10; i > 1; i--)
//	{
//		cout << sub(i, i + 1) << endl;
//	}
//	//内联函数声明和定义不能分离，直接定义在头文件
//	fun(10);
//}



//基于范围的for循环
//int main()
//{
//	int array[] = { 1,2,3,4,5,6,9 };
//	for (int e : array)
//	{
//		cout << e <<endl;
//	}
//		int x = 10;
//		auto a = &x;
//		auto* b = &x;
//		auto& c = x;
//		cout << typeid(a).name() << endl;
//		cout << typeid(b).name() << endl;
//		cout << typeid(c).name() << endl;
//		*a = 20;
//		*b = 30;
//		c = 40;
//}
	
//指针空值nullptr

//void  f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f( nullptr);
//}

//第一种类定义方式，声明定义放一起
//class Stack
//{
//	//成员函数
//public:
//	void init(int defaultcapacity=4)
//	{
//		a = (int*)malloc(sizeof(int) * capacity);
//		if (a == NULL)
//		{
//			perror("failed");
//		}
//		top = 0;
//		capacity = defaultcapacity;
//
//	}
// 
//	void Push(int x)
//	{
//		//扩容...
//		a[top] = x;
//		top++;
//	}
//	int Top()
//	{
//		return a[top - 1];
//	}
//
//	void Destroy()
//		{
//			free(a);
//			a = nullptr;
//			top = capacity;
//		}
//	//成员变量
//private:
//	int* a;
//	int top;
//	int capacity;
//};


//第二种，声明和定义分离，定义在cpp

//int main()
//{
//	class Stack st1;
//	st1.init();
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//	st1.Push(4);
//	st1.Destroy();
//}

//类的实例化
//int main()
//{
//	Stack St1;
//	St1.top = 1;
//	St1.a = (int*)malloc(sizeof (int));
//	return 0;
//}


//类大小
//int main()
//{
//	sizeclass size;
//	size.size();
//}


class A1//类似设计图
	{
	public:
	
		void PrintA1()
		{
			cout << _a << endl;
		}
	//private:
		// 类成员变量
		int _a;
	};
//int main()
//{
//	//类实例化对象
//	A a1;
//	A a2;
//	cout << sizeof(A) << endl;
//	cout << sizeof(a1) << endl;//实例化
//	a1._a = 1;
//	a1.PrintA1();
//	a2._a = 100;
//	cout << sizeof(a2) << endl;
//	a2.PrintA();//公共区域
//
//	return 0;
//}




// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//	void f1() {}
//private:
//	int _a;
//};
//
//// 类中仅有成员函数
//class A2 {
//public:
//	void f2() {}
//};
//
//// 类中什么都没有---空类
//class A3
//{
//};
////空类比较特殊，编译器给了空类一个字节来唯一标识这个类的对象。
//int main()
//{
//	//cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	A2 a1;
//	A2 a2;
//	cout << &a1 << endl;
//	cout << &a2 << endl;
//
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1, d2;
//	d1.Init(2022, 1, 11);
//	d2.Init(2022, 1, 12);
//	d1.Print();
//	d2.Print();
//	
//	return 0;
//}


//class A
//{
//public:
//	void Print() {
//		cout<< "Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	
//	return 0;
//}



//对_a访问，是this->a
//class A
//{
//public:
//	void Print() const{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//
//	return 0;
//}


typedef int stacktype;
class Stack
{
public:

	//构造函数
	 Stack(/*int capacity=4*/)
	{
		_a = (stacktype*)malloc(sizeof(stacktype)*4);
		if (_a == nullptr)
		{
			perror("malloc  failure!!!");
			return;
		}
		_capacity = 4;
		_size = 0;
	}
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int _newcap = _capacity * 4;
			stacktype* _tmp = (stacktype*)realloc(_a, sizeof(stacktype) * _newcap);
		
			if (_tmp == NULL)
			{
				perror("realloc申请空间失败!!!");
				return;
			}
		_a = _tmp;
		_capacity = _newcap;
		}

	}
	void Push(stacktype data)
	{
		CheckCapacity();
		_a[_size] = data;
		_size++;
	}
	void Pop()
	{
		if (Empty())
			return;
		_size--;
	}
	stacktype Top() { return _a[_size - 1]; }
	int Empty() const
	{ 
		return 0 == _size; 
	}
	int Size()const 
	{ 
		return _size;
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
//
//int main()
//{
//	Stack s;
//	//s.init();
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	while (!s.Empty())
//	{
//		cout << s.Top() << endl;
//		s.Pop();
//	}
//	//s.Destroy();
//	return 0;
//}
//有了构造和析构函数，就不用担心忘记初始化和销毁


class Date
{
public:
	//默认构造函数
	/*Date()
	{
		_year = 2022;
		_month = 2;
		_day = 2;
	}*/
	// 2.带参构造函数
	Date(int year, int month=12, int day=21)
	{
		_year = year;
			_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	//内置类型
	//非初始化，是声明，给的是默认缺省，给编译器默认生成构造函数用
	int _year=1;
	int _month=2;
	int _day=4;
	//
	//Stack _d1;
};
int main()
{
	//没有自定义写，就用默认构造
	//Date d1;
	//d1.Print();
	//显示写了，不用缺省值
	Date d2(100);
	//Date d1(); // 不可以这样写，会跟函数声明有点冲突，编译器不好识别
	Date d3(2026, 1, 22);
	d2.Print();
	d3.Print();

	//Date d3(2026);
	//d3.Print();
	return 0;
}