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


//class A
//{
//public:
//		A() { ++_scount; }
//		A(const A & t) { ++_scount; }
//		~A() { --_scount; }
//		static int GetACount() { return _scount; }
//private:
//		static int _scount;
//};
//
//int A::_scount = 0;
//void TestA()
//
//{
//		cout << A::GetACount() << endl;
//		A a1, a2;
//		A a3(a1);
//		cout << A::GetACount() << endl;
//}
//int main()
//{
//	TestA();
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a = 0)" << endl;
//	}
//	A(const A& a)
//		:_a(a._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& a)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//
//		if (this != &a)
//		{
//			_a = a._a;
//		}
//
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//void Func1(A aa)
//{
//
//}
//
//void Func2(const A& aa)
//{
//
//}
//
//A Func3()
//{
//    A aa;
//    return aa;
//}
//
//A& Func4()
//{
//    static A aa;
//    return aa;
//}
//A Func5()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//   //A a1;
//    //Func1(a1);
//   // Func2(a1);
//
//    //Func3();
//    //Func4();
//    A ra= Func5();
//	A raa;
//	raa = Func5();
//
////Func5();
//	//A aa1;//构造
//	//Func1(aa1);//拷贝构造
//	//Func1(A(1));//构造
//	//A aa2 = 2;//构造
//    return 0;
//}

//int main()
//{
//	//C
//	int* p1 = (int*)malloc(sizeof(int));
//	
//	int* p2 = (int*)malloc(sizeof(int)*10);
//	free(p1);
//	free(p2);
//
//	//c++
//	int* p3 = new int;
//	delete[]p3;
//	int* p4 = new int(10);
//	delete[]p4;
//	int* p6 = new int[10] {1, 2, 3};
//    delete[] p6;
//	return 0;
//}

//typedef struct ListNode
//{
//	int _data;
//	struct ListNode* next;
//	ListNode(int x)
//		:_data(x)
//		,next(NULL)
//	{ }
//}ListNode;
// ListNode* BuyListNode(int x)
//{
//	 ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//	 if (newnode==NULL)
//	 {
//		 perror("no");
//		 return NULL;
//	 }
//	 newnode->next = NULL;
//	 newnode->_data = x;
//	 return newnode;
//}
//
// int main()
// {
////ListNode* n1 = BuyListNode(1);
////ListNode* n2 = BuyListNode(2);
////ListNode* n3 = BuyListNode(3);
//ListNode* a1 = new ListNode(10);
//ListNode* a2 = new ListNode(11);
//ListNode* a3 = new ListNode(12);
//int* b1 = new int[5]; //随机值
//
//int* b1 = new int[5] {0};//全部初始化为0
//delete[]b1;
// }

class A
{
public:
	A(int a=1)
		:_a(a)
	{
		cout << "A()" << endl;
	}
	A(const A& a)
		:_a(a._a)
	{}
	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};
int main()
{
A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	A* p3 = new A[10];
	free(p1);
	delete p2;
}


