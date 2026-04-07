#pragma once
#include<assert.h>
//#include<iostream>
//using namespace std;
//命名空间域
namespace wj
{
	template<class T>
	class A
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		size_t size()const
		{
			return _finish - _start;
		}
		iterator begin()const
		{
			return  _start;
		}
		iterator begin()
		{
			return  _start;
		}
		iterator end()const
		{
			return  _finish;
		}
		iterator end()
		{
			return  _finish;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}
		A()
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr)
		{ }
		//(1)传统写法,自己开空间自己拷贝
		/*A(const A<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			_start = new T[v.capacity()];
			memcpy(_start, v._start, sizeof(T) * v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}*/

		//（2）开空间push_back
		A(const A<T>& v)
		
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{

			for (auto e : v)
			{
				push_back(e);
			}
		}
		void swap( A<T>& v)
		{
			std::swap(_start,v._start);
			std::swap(_finish,v._finish);
			std::swap(_end_of_storage,v._end_of_storage);
		}
		A<T>& operator=( A<T> v)
		{
			//用库里std的
			swap(v);
			return *this;
		}
		A(size_t n, const T val= T())
		{
			resize(n, val);
		}
		/*A(int n, const T val = T())
		{
			resize(n, val);
		}*/
		template<class InputIterator>
		A(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		~A()
			
		{ 
			delete[]_start;
		_start = _finish = _end_of_storage = nullptr;
		}
		void reserve(size_t n)
		{
			//扩容数量>当前容量	
			if (n>capacity())
			{
				//空间不为空
				T* tmp = new  T[n];
				//提前保存一个,不然后面size()函数中_start是新空间，但是_finish是旧空间
				size_t sz = size();
				if (_start)
				{

					for (size_t i = 0; i < sz; i++)
					{
						//本质是赋值重载,使用memcpy导致string对象浅拷贝
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void insert(iterator pos,const T&x)
		{
			assert(pos >= begin() && pos <=end());

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			//转移数据
			while (end>=pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;

		}
		void push_back( const T& x)
		{
			//考虑扩容
			if (_finish==_end_of_storage)
			{
				
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
			//insert(end(),x);
		}
		iterator erase(iterator  pos)
		{
			assert(pos>=begin()&&pos<=end());
			iterator end =pos + 1;
			while (end  < _finish)
			{ 
				*(end - 1) = *end;
				end++;
			}
			_finish--;
			return  pos;
		}
		//C++中，内置类型也可以支持默认构造
		void resize(size_t n,const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n) 
				{
					*_finish = val;
					_finish++;
				}
				
			}
		}
		
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
	void print(const  A<int>& v)
	{
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	
	void test_vector1()
	{
		A<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(6);
		v1.push_back(7);
		v1.push_back(4);
		for (auto e:v1)
		{
			cout << e << " ";
		}
		cout << endl;
		for (size_t i = 0; i < v1.size(); i++)
		{
			v1[i]++;
		}

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		//print(v1);
	}
	void test_vector2()
	{
		A<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(8);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		v1.insert(v1.begin()+2, 10);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
		v1.erase(v1.begin()+2);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_vector3()
	{
		A<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(8);
		v1.push_back(5);
		v1.push_back(26);
		
		auto it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{

				//返回的是所删除元素的下一个位置，用返回值，库里也是返回一个iteraror
				it = v1.erase(it);
			}
			else
			{
				it++;
			}
		}

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_vector4()
	{
		A<int>v4;
		v4.resize(12);
		for (auto e : v4)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void test_vector5()
	{
		A<int >v5;
		v5.push_back(1);
		v5.push_back(2);
		v5.push_back(3);
		v5.push_back(4);
		v5.push_back(5);
		A<int >v6(v5);//深拷贝
		for (auto e : v6)
		{
			cout << e << " ";
		}
		cout << endl;
		A<int >v2;
		v2.resize(10, 1);

		v6 = v2;//赋值重载
		for (auto e : v6)
		{
			cout << e << " ";
		}
		cout << endl;

	}
	void test_vector6()
	{
		A<string>v;
		v.push_back("111111111111111");
		v.push_back("33333333333333333333333");
		v.push_back("5555555555555555");
		v.push_back("77777777777777777777777777");
		v.push_back("88888888888888888888888888");
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		A<string>v2(v);

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

	}
	void test_vector7()
	{
		//A<int >v1(10, 1);
		A<string >v2(10, "*****");
		A<int >v3(10u, 1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}