
#include <iostream>
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
int main()
{
    int a = 0, b = 1;
    double c = 1.1, d = 2.2;
   // Swap(a,b); 
    cout << a <<endl << b << endl;
    swap(a, b);
    cout << a << endl << b << endl;
    swap(c, d);
    cout << c << endl<< d << endl;
    int* p1 = &a;
   int* p2 = &b;


    swap(p1,p2);
    cout << p1 << endl <<p2<< endl;

    return 0;
}
