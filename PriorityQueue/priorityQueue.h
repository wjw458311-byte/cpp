#pragma once

#include<vector>
namespace wj
{
	template<class T, class Container = vector<T>>
	class priorityqueue
	{
		//先输入数据
	private:
		//大堆
		void Adjustdown(int partent)
		{
			size_t child = partent * 2 + 1;
			//每个堆
			while (child<_con.size())
			{
				//判断左右孩子哪个大
				if (child+1< _con.size() && _con[child] < _con[child + 1])
				{
					child++;
				}
				//交换,孩子比父亲大的
				if (_con[child] > _con[partent])
				{
					swap(_con[child], _con[partent]);
					partent = child;//更新父节点和孩子节点位置，继续往下
					child = partent * 2 + 1;
				}
				else
				{
					break;
				}
			}
			
		}
		
		void Adjustup(int child)
		{
			size_t  partent = (child - 1) / 2;
			//大堆
			while (child>0)
			{
				if (_con[child]>_con[partent])
				{
				swap(_con[child] ,_con[partent]);
				child = partent;
				partent = (child - 1) / 2;
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
	
		priorityqueue<int> pq;

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


}
