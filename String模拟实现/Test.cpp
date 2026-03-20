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
void Teststring3()
{
	wj::string s1("helloworld");
	cout << s1.c_str() << endl;

	s1.insert(5, 3, '#');
	cout << s1.c_str() << endl;

	s1.insert(0, 3, '#');
	cout << s1.c_str() << endl;


	wj::string s2("helloworld");
	s2.insert(5, "%%%%%");
	cout << s2.c_str() << endl;
}
void Teststring4()
{
	wj::string s1("helloworld");
	cout << s1.c_str() << endl;

	s1.erase(5, 20);
	cout << s1.c_str() << endl;

}
void Teststring5()
{
	
	wj::string url = "ftp://www.baidu.com/?tn=65081411_1_oem_dg";

	size_t pos1 = url.find("://");
	if (pos1 != wj::string::npos)
	{
		wj::string protocol = url.substr(0, pos1);
		cout << protocol.c_str() << endl;
	}

	size_t pos2 = url.find('/', pos1 + 3);
	if (pos2 != wj::string::npos)
	{
		wj::string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
		wj::string uri = url.substr(pos2 + 1);

		cout << domain.c_str() << endl;
		cout << uri.c_str() << endl;
	}
}
void Teststring6()
{
	wj::string s1("hello world");
	s1.resize(7,'\0');
	cout << s1.c_str() << endl;
	s1.resize(10,'x');
	cout << s1.c_str() << endl;
	s1.resize(15, 'o');
	cout << s1.c_str() << endl;
}
int main()
{
	Teststring6();
	return 0;
}