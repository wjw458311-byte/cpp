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
int main()
{
	sizeclass size;
	size.size();
}