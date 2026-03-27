#include<vector>

#include <iostream>
#include<algorithm>
using namespace std;
void vector1()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (size_t i = 0; i <v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;
	//迭代器
	vector<int >::iterator it = v.begin();
	while (it!=v.end())
	{
		cout << *it ;
		it++;
	}
	cout << endl;
	vector<string> w;
	w.push_back("wujun");
	vector<int > v1(5,1);
	vector<string > v2(10, "1");
}
void vector2()
{
	vector<int > v1(5, 1);
	vector<string > v2(10, "abc");
	vector<int>::iterator vit = v1.begin();
	while (vit != v1.end())
	{
		cout << *vit;
		vit++;
	}
	cout << endl;
	vector<string>::iterator vit2 = v2.begin();
	while (vit2 != v2.end())
	{
		cout << *vit2;
		vit2++;
	}
	cout << endl;
	vector<int> v3(v1.begin(), v1.end());
	for (auto v:v3)
	{
		cout << v;

	}
	cout << endl;
	string str("hello world");
	vector<char> v4(str.begin(), str.end());
	for (auto e : v4)
	{
		cout << e;
	}
	cout << endl;
	vector<char> v5(str.rbegin(), str.rend());
	for (auto e : v5)
	{
		cout << e ;
	}
	cout << endl;
	//数组
	int a1[] = { 12,4,56,7,999 };


	//迭代器区间是左闭右开，指针走不到a1+5，那是最后一个数的下一个位置
	vector<int> v6(a1,a1+5);
	for (auto e : v6)
	{
		cout << e<<" ";
	}
	cout << endl;
	sort(v6.begin(), v6.end());
	sort(v5.begin(), v5.end());
	sort(v6.rbegin(), v6.rend());
	//greater<int> gt;
	for (auto e : v6)
	{
		cout << e << " ";
	}
	cout << endl;
	//降序
	sort(v6.begin(), v6.end());
	for (auto e : v6)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//vector1();
	vector2();
	return 0;
}