#include<stdio.h>
#include<stdlib.h>


//错误的，命名冲突
//int rand = 100;
//int main()
//{
//	printf("%d ",rand);
//	return 0;
//}





////第一种方法,命名空间名加限定符::
//int main()
//{
//	
//	printf("%d\n",::a);//域作用限定,访问全局变量
//	printf("%d\n",wj::a);//指定访问命名空间域
//	printf("%d\n",b);//局部展开
//
//}

//using wj::b;
////第二种方法,局部展开命名空间
//int main()
//{
//	
//	printf("%d\n",::a);//域作用限定,访问全局变量
//	printf("%d\n",wj::a);//指定访问命名空间域
//	printf("%d\n",b);//局部展开

//int a = 4;
//double b = 2.2;
//namespace wj
//{
//	int a = 1;
//	int b = 2;
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//}
////第三种，using把命名空间全部展开
//using namespace wj;
////要是有冲突的话，单独写a是编译不过的，有全局变量和空间内变量同时存在
//int main()
//{
//
//	printf("%d\n", wj::b);//空间内
//	printf("%f\n", ::b);//全局
//	printf("%d\n",::a);//全局变量
//	printf("%d\n",wj::a);//命名空间内
//	printf("%d\n",add(13,4));
//	
//}


//没有冲突

//namespace wj
//{
//	int a = 100;
//	double b = 2.332;
//	int Add(int a ,int c)
//	{
//		return a + c;
//	}
//}
////命名空间全部展开
//using namespace wj;
//int main()
//{
//	printf("%d\n",a);
//	printf("%.2f\n",b);
//	printf("%d\n",Add(2,3));
//	return  0;
//}


//局部域->全局->展开的命名空间域or指定的命名空间域
//int a = 11;
//
//namespace wj
//{
//	double a = 2.34;
//	float b = (float)2.1;
//	char c = 'n';
//	char d[] = "abc";
//}
//using namespace  wj;
//int main()
//{
//	int a = 2;
//	
//	printf("%d\n",::a);//全局
//	printf("%d\n",a);//局部
//	printf("%lf\n",wj::a);//命名空间内
//	printf("%f\n",b);//命名空间
//	printf("%c\n",c);//命名空间
//	printf("%s\n",d);//命名空间
//
// }

//嵌套
//namespace N1
//{
//    int a = 0;
//    int b;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//
//    namespace N2
//    {
//        int a = 1;
//        int c;
//        int d;
//        int Sub(int left, int right)
//        {
//            return left - right;
//        }
//    }
//}
//int main()
//{
//    printf("%d\n",N1::b);
//    printf("%d\n",N1::a);
//    printf("%d\n",N1::Add(232,435));
//    printf("%d\n",N1::N2::c);
//    printf("%d\n",N1::N2::Sub(2,7));
//}


//#include<iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	std::cout << "hello world" << std::endl;
//	std::cout << "hello world" << std::endl;
//	std::cout << "hello world" << std::endl;
//  }

//全部展开
//#include<iostream>
//using namespace std;
////风险是可能会和c++标准库冲突，最好指定访问，防止冲突定义
//int main()
//{
//	cout << "hello wor ld" << endl;
//}


//部分展开,展开常用的运算符
//#include<iostream>
//using  std::cout;
//using  std::endl;
//int main()
//{
//	cout << "hello world"<<endl ;
//	std::cout << "hello world"<< std::endl;
//}

//#include<iostream>
//using  std::cout;
//using  std::cin;
//using  std::endl;
//int main()
//{
//	int a;double b;
//	cin >> a>> b;
//	printf("%d,%.2lf\n", a, b);
//	cout << a << endl << b << endl;
//	int c = 20;
//	double d = 20.312;
//	cout << c << endl << d << endl;
//}



#include<iostream>
//using namespace std;
using std::cout;
using std::endl;
//void add(int a = 2)
//{
//	int b = 3;
//	cout << a*b << endl;
//}
//int main()
//{
//	add();
//	add(4);
//	return 0;
//}


//全缺省参数
//void func(int a=2,int b=3)
//{
//	cout<< a * b<<endl;
//	cout<< a /b<<endl;
//}
//
//int main()
//{
//	func();
//	func(5,100);
//	return 0;
//}


//半缺省参数,至少一个没有指定实参,从右往左缺
//没有给实参，就用缺省值(一定会有，不然无法编译)，有给定实参，就会替换掉缺省值
//void func(int a, int b , int c = 10)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//} 
//
//int main()
//{
//	func(1,2);
//	return 0;
//}
//缺省函数，声明给，定义不用给

//#include"SeqList.h"
//void SLPushBack(SL** sl, int x = 20);
//int main()
//{
//	SL *sl=NULL;
//	SLPushBack(&sl);
//	SLPushBack(&sl,100);
//}

//函数重载
//类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//
//	return left + right;
//}
//
//
//void f(int a, char b)
//{
//	cout <<a <<b<< endl;
//}
//void f(char b, int a)
//{
//	cout << b <<a<< endl;
//}
//void f()
//{
//	cout <<  'a' << endl;
//}
//void f(int a)
//{
//	cout <<a << endl;
//}
//
//int main()
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f(1);
//	f(10);
//	f(10, 'a');
//	f('a',10);
//	return 0;
//}






////////////////////////////////////////
//引用

#include<iostream>
using std::cout;
using std::endl;

//int main()
//{
//int a = 0;
//int& b = a;
//int& c = b;
//int& d = c;
//a = 10;
//c = 15;
//cout << a << endl;
//cout << d << endl;
//return 0;
//}

//正确,
//int count()
//{
//	static int n = 10;
//	n++;
//	return n;
//}
//
//int main()
//{
//	int ret = count();
//	cout << ret << endl;
//}



//传值返回
//int count()
//{
//	 int n = 10;
//	n++;
//	return n;
//}
//
//int main()
//{
//	int ret = count();
//	cout << ret << endl;
//}



//引用返回，越界访问问题
//int& count(int x)
//{
// int n = x;
//	n++;
//	return n;
//}
//
//int main()
//{
//	
//	int& ret = count(10);
//	cout << ret << endl;
//	cout << "aaa" << endl;
//	cout << ret << endl;
//
//
//}

//正确做法
//int& count(int x)
//{
//	static int n = x;
//	n++;
//	return n;
//}
//
//int main()
//{
//	/*int ret = count();
//	cout << ret << endl;*/
//	int& ret = count(10);
//	cout << ret << endl;
//	cout << &ret << endl;
//	cout << "aaa" << endl;
//	cout << &ret << endl;
//
//
//}

//引用权限可以平移，缩小，但不能放大
//int main()
//{
//	//const作为常量值，被修饰的不可以被改变
//	const int a = 1;
//	//a=1l
//	//int& b = a;a不可以被改变，a的引用依旧不能改
//	int d = a;//赋值可以
//}


//int main()
//{
//	//ok
//	int x = 1;
//	int& y = x;
//	const int& z = y;
//	x++;
//	//ok?no
//	//z ++
//
//	double d = 1.11;
//	int i = d;
//	int& ri = d;//权限不能放大，d到i发生了类型转换，是个常量 ×
//	const int& pi = d;//权限的平移  √
//}

//int func()
//{
//	static int x = 0;
//	return x;
//}
//int&  func2()
//{
//	static int y = 2;
//	return y;
//}
//int main()
//{
//	// int& ret = func();//不可以，返回的是临时变量，有常性
//	 const int& ret1 = func();//权限平移
//	 int ret2 = func();//拷贝
//	 int& ret3 = func2();//权限平移
//	 const int& ret4 = func2();//权限缩小
//}


//int main()
//{
//	int c = 1;
//	double d = 1.222;
//	if (c > d)
//	{
//		cout << "大于" << endl;
//	}
//	else
//		cout << "小于" << endl;
//}

int main()
	{
	//&是不开空间，取别名
	int a = 2;
	int& pa = a;

	pa = 20;
	cout << pa << endl;
	cout << &pa << endl;
	cout << &a << endl;//地址一样

	int b = 8;
	int* pb = &b;
	*pb = 1;
	
	
	cout << pb << endl;	
	cout << &b << endl;
	cout << *pb << endl;

	

	}
