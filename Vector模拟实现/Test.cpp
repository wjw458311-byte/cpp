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
void vector3()
{
	vector<int> v3;
	//不用reserve，它是只开空间，不会改变容器大小，用resize，开空间的同时会改变容器大小
	v3.resize(20);//已经开好空间了并且容器大小也是20 capacity=20;size=20;
	
	for (size_t i = 0; i < 20; i++)
	{
		v3[i] = i;
	}

		//迭代器指针指向数组的第一个元素
	vector<int>::iterator vit3 = v3.begin();
	while (vit3!=v3.end())
	{
		cout << *vit3 << ' ';

		vit3++;
	}
	cout << endl;

	//reserve版本
	vector<int > v4;
	v4.reserve(20);
	for (size_t i = 0; i < 20; i++)
	{
		v4.push_back(i);//这里进行大小扩容
	}
	for (auto e:v4)
	{
		cout << e << endl;
	}
}

//增删查改
void vector4()
{
	int a[] = { 16,2,40,29,3,38,43,3,2,6,6 };
	//数组名是首元素地址
	// //迭代器区间是左开右闭，是最后一个元素的下一个位置
	vector<int >v5(a, a + sizeof(a) / sizeof(int));
	for (auto e:a)
	{
		cout << e << ' ';
	}
	cout << endl;
	//头插入
	//iterator insert (iterator position, const value_type& val);
	//v5.insert(v5.begin(), 1);
	//任意位置插入n个
	//void insert (iterator position, size_type n, const value_type& val);
	v5.insert(v5.begin()+1, 2,5);
	// 插入一段范围，同样遵守左开右闭
	//void insert(iterator position, InputIterator first, InputIterator last);
	//v5.insert(v5.begin() , v5.begin()+1, v5.end()-4);
	
	for (auto e : v5)
	{
		cout << e << ' ';
	}
	cout << endl;
	//头删
	v5.erase(v5.begin());
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	//删掉第3个数据，begin指向第一个元素，加2就是第三个
	v5.erase(v5.begin() + 2);
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
	//删除某个元素，但是不知道在哪
	vector<int>::iterator pos1;
	pos1= find(v5.begin(), v5.end(), 6);
	if (pos1 != v5.end())
	{
		v5.erase(pos1);
	}
	for (auto e : v5)
	{
		cout << e << ' ';
	}
	cout << endl;
	//删除所有选定的元素
	vector<int>::iterator pos2 = find(v5.begin(), v5.end(), 3);

	while (pos2!=v5.end())
	{
		v5.erase(pos2);
		pos2= find(v5.begin(), v5.end(), 3);
	}
	for (auto e : v5)
	{
		cout << e << ' ';
	}
	cout << endl;
}
void vector5()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
//int main()
//{
//	//vector1();
//	//vector2();
//	//vector3();
//	vector4();
//	vector5();
//	return 0;
//}
#include"vector.h"
int main()
{
	wj::test_vector2();
}