
#include <iostream>
#include<vector>
//#include<string>
using namespace std;


class A
{
public:
    A(int a=2,int b=3)
        :_a(a)
    {
        cout << " A():" <<this<< endl;
    }
    A(const A& a)
        :_a(a._a)
    {
        cout << "  A(const A& a):" <<this<< endl;
    }
    ~A()
    {
        cout << " ~A():" << this << endl;
    }

private:
    int _a;
};


//int main()
//{
//    int* p1 = (int*)malloc(sizeof(int));
//    int* p2 = new int;
//    int* p3 = new int[10];
//    free(p1);
//    delete p2;
//    delete[] p3;
//}

//int main()
//{
// /*  A* p1 = (A*)malloc(sizeof(A));
//    A* p2 = new A(3);
//    A* p3 = new A[5];
//    free(p1);
//    delete p2;
//    delete []p3;*/
//    A* p5 = (A*)malloc(sizeof(A) * 10);
//    A* p6 = new A[4]{ A(1,1),A(2,2),A(3,3) };
//    A* p7 = new A[4]{ A(1,1),A(2,2),A(3,3),A(4,4) };
//    free(p5);
//    delete[] p6;
//    delete[] p7;
//    A* p1 = (A*)operator new(sizeof(A));
//    return 0;
//    
//}



//int main()
//{
//    int* p1 = nullptr;
//    do
//    {
//        p1 = new int[1024 * 1024];
//        cout << p1 << endl;
//    } while (p1);
//}


//int main()
//{
//    char* p1 = new char[1024 * 1024 * 1024] {'b', 'i', 't'};
//    cout << p1 << endl;
//
//    return 0;
//}

//void Swap(int &a1,int &a2)
//{
//    int tmp = a1;
//    a1 = a2;
//    a2 = tmp;
//}
//
//
//void Swap(double& a1, double& a2)
//{
//    double tmp = a1;
//    a1 = a2;
//    a2 = tmp;
//}
//
//void Swap(char& a1, char& a2)
//{
//    char tmp = a1;
//    a1 = a2;
//    a2 = tmp;
//}

//函数模板
template <typename T>
void Swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
//int main()
//{
//    int a = 0, b = 1;
//    double c = 1.1, d = 2.2;
//   // Swap(a,b); 
//    cout << a <<endl << b << endl;
//    swap(a, b);
//    cout << a << endl << b << endl;
//    swap(c, d);
//    cout << c << endl<< d << endl;
//    int* p1 = &a;
//   int* p2 = &b;
//    swap(p1,p2);
//    cout << p1 << endl <<p2<< endl;
//
//    return 0;
//}

template <typename T1,typename T2>
void  Func(const T1&x1,const T2&x2)
{
    cout << x1 << "  " << x2 << endl;
   
}

//int main()
//{
//    int a = 0, b = 1;
//    Swap(a, b);
//
//    double c = 1.1, d = 2.2;
//    Swap(c, d);
//
//    Func(1, 2);
//    Func(1, 2.2);
//    return 0;
//}

//template <typename T>
////隐式实例化
//T Add(const T& x, const T &y)
//{
//    return x + y;
//}
// int main()
//{
//    int a1 = 10, a2 = 20;
//    double d1 = 10.1, d2 = 20.2;
//    // 实参传递的类型，推演T的类型
//    cout << Add(a1, a2) << endl;
//    cout << Add(d1, d2) << endl;
//    cout << Add((double)a1, d2) << endl;
//
//    //显示实例化
//    cout << Add<int>(a1, d2) << endl;
//    cout << Add<double>(a1, d2) << endl;
//}

//int类型
//typedef int datatype;
//class Stackint
//{
//public:
//    //Stackint(datatype capacity = 3)
//    //    //malloc
//    //    :_arr(nullptr)
//    //    ,_size(0)
//    //    ,_capacity(capacity)
//    //{
//    //    _arr = (datatype*)malloc(sizeof(datatype));
//    //    if (_arr = NULL)
//    //    {
//    //        perror("fail");
//    //        return;
//    //    }
//    //}
//    Stackint(datatype capacity = 3)
//    
//        :_arr(new datatype[capacity])
//         ,_capacity(capacity)
//        ,_size(0)
//        {}
//    ~Stackint()
//    {
//        delete[]_arr;
//    }
//    void PushStack(datatype x)
//    {
//        _arr[_size++] = x;
//    }
//private:
//    datatype* _arr;
//    int _size=0;
//    int _capacity;
//};
//
//
//typedef double datatype;
//class Stackdouble
//{
//public:
//    
//    Stackdouble(datatype capacity = 3)
//
//        :_arr(new datatype[capacity])
//        , _capacity(capacity)
//        , _size(0)
//    {
//    }
//    ~Stackdouble()
//    {
//        delete[]_arr;
//    }
//    void PushStack(datatype x)
//    {
//        _arr[_size++] = x;
//    }
//private:
//    datatype* _arr;
//    int _size = 0;
//    int _capacity=0;
//};
// int main()
//{
//	Stackint s1; // int
//	Stackdouble s2; // double
//	return 0;
//}

//类模板
//template <class T>
//class Stack
//{
//public:
//    Stack(int capacity = 3);
//    void PushStack(const T& x);
//    ~Stack()
//    {
//        delete[]_arr;
//    }
//   
//private:
//    T* _arr;
//    int _capacity = 0;
// int _size = 0;
//};
//
//template<typename T>
//Stack<T>::Stack(int capacity )
//    :_arr(new T[capacity])
//    , _capacity(capacity)
//    , _size(0)
//{
//}
//template<typename T>
//void Stack<T>::PushStack(const T& x)
//{
//    _arr[_size++] = x;
//}
//
//int main()
//{
//   Stack<int> s1;
//   Stack<double> s2;
//}

//int main()
//{
//    string name;
//    string name1("张三");
//    string name2("hellooo");
//    name2 = "wujun";
//    string s1(10,'@');
//    string s2(name2);
//    string s3(name2,2,100);//取到最后
//    cout << name << endl;
//    cout << (s1>name2) << endl;
//    cout << name2 << endl;
//    cout << s3 << endl;
//}

//int main()
//{
//    //增
//    string name1("hello");
//    string name2(" China");
//    //name1.append(" world");//尾插一个字符串
//    name1.append(name2);
//    name1 += " world";
//    cout << name1 << endl;
//}

#include<algorithm>

//int main()
//{
//    //遍历string
//    string s1("hello world ");
//    /*for (int i = 0; i < s1.size(); i++)
//    {
//        s1[i]++;
//    }*/
//    for (int i = 0; i <s1.size(); i++)
//    {
//        cout << s1[i]<<"->";
//    }
//    cout << endl;
//    string::iterator it = s1.begin();
//    while(it !=s1.end())
//    {
//        cout << *it;
//        it++;
//    }
//    cout << endl;
//
//   /* for (auto& ch:s1)
//    {
//        ch++;
//        cout << ch << "->";
//
//    }
//    cout << endl;*/
//
//  
//    vector<int> v;
//    v.push_back(1);
//    v.push_back(3);
//    v.push_back(20);
//    v.push_back(7);
//    v.push_back(9);
//    vector<int>::iterator vit = v.begin();
//    while(vit!=v.end())
//    { 
//        cout << *vit;
//        vit++;
//    }
//    cout << endl;
//    cout << " ----------------";
//    reverse(s1.begin(), s1.end());
//    reverse(v.begin(), v.end());
//    sort(v.begin(), v.end());
//    for (auto& e : s1)
//    {
//        cout << e;
//    }
//    cout << endl;
//    for (auto& e : v)
//    {
//        cout << e;
//    }
//    cout << endl;
//
//}

//void func(const string &s)
//{
//    //string::const_iterator it = s.begin();
//    auto it = s.begin();
//    while (it != s.end())
//    {
//
//        cout << *it<< "-";
//        it++;
//    }
//    cout << endl;
//    auto rit = s.rbegin();
//    while (rit != s.rend())
//    {
//
//        cout << *rit<< "-";
//        rit++;
//    }
//    cout << endl;
//}
//int main()
//{
//    string s1("hello world");
//    //正向遍历可读写
//    string::iterator it = s1.begin();
//    while (it!=s1.end())
//    {
//        *it += 1;
//        cout << *it<<"-";
//        it++;
//    }
//    cout << endl;
// 
//    //逆向可读写
//    auto rit = s1.rbegin();
//    while (rit != s1.rend())
//    {
//        *rit -= 1;
//        cout << *rit<< "-";
//        rit++;
//    }
//    cout << endl;
//    //只读
//    func(s1);
//
//
//}


int main()
{
	string s1("hello world");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	//cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;

	size_t old = s1.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		s1 += 'x';

		if (old != s1.capacity())
		{
			cout << "扩容：" << s1.capacity() << endl;
			old = s1.capacity();
		}

	}

	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	s1.clear();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	return 0;
}