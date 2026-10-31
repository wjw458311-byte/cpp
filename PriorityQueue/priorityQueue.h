#pragma once
//#include<functional>
#include<vector>

namespace wj
{
	/*template<class T>
	struct Less
	{

		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T>

	struct Greater
	{

		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};*/
	template<class T, class Container = vector<T>, class Compare = greater<T>>
	class priorityqueue
	{
		//先输入数据
	private:
		//大堆
		void Adjustdown(int parent)
		{
			size_t child = parent * 2 + 1;
			//每个堆
			while (child<_con.size())
			{
				Compare com;
				//判断左右孩子哪个大
				if (child+1< _con.size() && com(_con[child] , _con[child + 1]))
				{
					child++;
				}
				//交换,孩子比父亲大的
				if (com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;//更新父节点和孩子节点位置，继续往下
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
			
		}
		
		void Adjustup(int child)
		{
			size_t  parent = (child - 1) / 2;
			//大堆
			while (child>0)
			{
				Compare com;
				if (com(_con[parent], _con[child]))
				{
				swap(_con[child] ,_con[parent]);
				child = parent;
				parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
			
		}
		public:
			priorityqueue()
			{
			}
			template<class InputIterator>
			priorityqueue(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					_con.push_back(*first);
					first++;
				}
				for (size_t i = (_con.size()-2)/2; i >=0; i--)
			{
				//从最后一个有孩子的节点开始依次往前向下调整
				Adjustdown(i);
			}
			}
			//建堆，插入用向上调整，删除用下沉
			//最后一个元素下标是n-1，孩子的下标为child，父节点为（child-1）/2
			//那么最后一个节点的父节点为（n-1-1）/2
			
			void push(const T&x)
			{
				_con.push_back(x);
				Adjustup(_con.size()-1);

			}
			void pop()
			{
				swap(_con[0],_con[_con.size()-1]);
				_con.pop_back();
				Adjustdown(0);

			}
			size_t size()
			{
				return _con.size();
			}
			bool empty()
			{
				return _con.empty();
			}
			T&  top()
			{
				return _con[0];
			}
		private:
			Container _con;

	
	};

	void test_priorityqueue1()
	{
	
		priorityqueue<int,vector<int>,less<int>> pq;
	//	priorityqueue<int> pq;

		pq.push(3);
		pq.push(5);
		pq.push(1);
		pq.push(4);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
	class Date
	{
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
		{}

		bool operator<(const Date& d)const
		{
			return (_year < d._year) ||
				(_year == d._year && _month < d._month) ||
				(_year == d._year && _month == d._month && _day < d._day);
		}

		bool operator>(const Date& d)const
		{
			return (_year > d._year) ||
				(_year == d._year && _month > d._month) ||
				(_year == d._year && _month == d._month && _day > d._day);
		}

		friend ostream& operator<<(ostream& _cout, const Date& d);
	private:
		int _year;
		int _month;
		int _day;
	};

	ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

	/*struct LessPDate
	{
		bool operator()(const Date* p1, const Date* p2)
		{
			return *p1 < *p2;
		}
	};*/

	void test_priorityqueue2()
	{
		// 仿函数控制实现小堆
		priorityqueue<Date, vector<Date>, greater<Date>> pq;
		pq.push(Date(2023, 7, 20));
		pq.push(Date(2023, 6, 20));
		pq.push(Date(2023, 8, 20));

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}
