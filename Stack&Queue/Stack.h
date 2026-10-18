#pragma once
#include<vector>
#include<list>
namespace wj
{

	template<class T, class container>
	class Stack
	{
	public:
		void push(const T& x)
		{
			con.push_back(x);
		}
		void pop()
		{
			con.pop_back();
		}
		T& top()
		{
				return con.back();

		}
		size_t size()

		{
			return con.size();
		}
		bool empty()
		{
			return con.empty();
		}
	private:
		container con;
	};
	void test_stack()
	{
		Stack<int, vector<int>>st1;
		Stack<int, list<int>>st2;
		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);
		st1.push(5);
		while (!st1.empty())
		{
			cout << st1.top() << endl;
			st1.pop();
		}
		st2.push(1);
		st2.push(2);
		st2.push(3);
		st2.push(4);

		while (!st2.empty())
		{
			cout << st2.top() << " ";
			st2.pop();
		}
		cout << endl;
	}


}
