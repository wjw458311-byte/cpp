#define  _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

#include <iostream>

using namespace std;


//int main()
// {
//	wj::string s1("hello world");
//	cout << s1.c_str() << endl;
//	wj::string s2;
//	cout << s2.c_str() << endl;
//	for (size_t i= 0;i <s1.size() ; i++)
//	{
//		cout << s1[i] ;
//	}
//	cout << endl;
//	const wj::string s3("hello world");
//	wj::string::iterator it = s1.begin();
//	/*while (it!=s1.end())
//	{
//
//		cout << *it << "";
//		it++;
//	}
//
//	cout << endl;*/
//	//Óï·¨ÌÇ
//	for (auto ch : s1)
//	{
//		cout << ch << "";
//	}
//	cout << endl;
//	wj::string:: const_iterator cit = s3.begin();
//	while (cit!=s3.end())
//	{
//		
//		cout << *cit << "";
//		cit++;
//	}
//	cout << endl;
//	return 0;
//}

void Teststring2()
{
	 wj::string s1("hello world");
	 cout << s1.c_str() << endl;

	 s1.push_back(' ');
	 s1.push_back('@');
	 s1.append("wj");
	 cout << s1.c_str() << endl;
	 wj::string s2("hello world");
	 s2 += '(';
	 s2 += "(1)";
	
	 cout << s2.c_str() << endl;

}
int main()
{
	Teststring2();
	return 0;
}