#pragma once
#include<vector>
#include<list>
namespace wj
{

	template<class T, class container>
	class queue
	{
	public:
		void push(const T& x)
		{
			con.push_back(x);
		}
		void pop()
		{
			con.pop_front();
		}
		T& front()
		{
			return con.front();

		}
		T& back()
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
	void test_queue()
	{
		queue<int, list<int>> q;

		//queue<int, vector<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}