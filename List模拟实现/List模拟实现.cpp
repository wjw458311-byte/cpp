#pragma once
#include<algorithm>
#include<iostream>
#include<assert.h>
using namespace std;
namespace wj
{
	//双链表的节点
	template <class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;
		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{}
	};
	//构造迭代器，用于遍历容器
	template<class T, class Ref,class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref,Ptr> self;
		Node* _node;//指向节点的指针

		//用已有节点构造迭代器
		_list_iterator(Node* node)
			:_node(node)
		{}
		Ref& operator*()
		{
			return _node->_val;
		}
		Ptr operator->()
		{
			return &_node->_val;
		}
		//前置++
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		//后置++
		self operator++(int)
		{
			self tmp(*this);

			_node = _node->_next;

			return tmp;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);

			_node = _node->_prev;

			return tmp;
		}
		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;
		size_t size()
		{
			return sz;
		}
		iterator begin()
		{
			return head->_next;

		}
		const_iterator begin()const
		{
			return head->_next;

		}
		iterator end()
		{
			return head;

		}
		const_iterator end() const
		{
			return head;

		}
		//pos位置之前插入x
		iterator insert(iterator pos, const T& val = T())

		{
			Node* cur = pos._node;
			//记录前一个节点的指针
			Node* prev = cur->_prev;
			Node *newnode=new Node(val);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;	
			++sz;
			return newnode;

		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			//记住当前节点
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = cur->_next;
			cur->_next->_prev = prev;
			delete cur;
			--sz;
			return next;
		}
		//构造双链表
		list()
		{
			//下个节点和前驱都指向自己
			head = new Node;
			head->_next = head;
			head->_prev = head;
			sz = 0;
		}
		~list()
		{
			delete head;
			head = nullptr;

		}
		//拷贝构造
		list(const list<T>& lt)
		{
			head = new Node;
			head->_next = head;
			head->_prev = head;
			sz = 0;
			for (auto& e : lt)
			{
				push_back(e);
			}
		}
		void swap( list<T>& lt)
		{
			std::swap(head, lt.head);
			std::swap(sz, lt.sz);
		}
		//赋值，现代写法
		list<T>&  operator=( list<T>& lt)
		{
			swap(lt);
			return *this;
		}
		//清零
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
			sz = 0;
		}
		//尾插
		void  push_back(const T& x)
		{
			////尾节点
			//Node* tail = head->_prev;
			////连接新节点
			//Node* newnode = new Node(x);
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = head;
			//head->_prev = newnode;
			insert((end()), x);
		}
		//尾删
		void  pop_back()
		{
			erase(--(end()));
		}
		//头插
		void push_front(const T& x)
		{
			insert(begin(),x);
		}
		//头删
		void pop_front()
		{
			erase(begin());
		}
	private:
		Node* head;
		size_t sz;
	};

}
//int main()
//{
//	wj::list<int >lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//	lt.push_back(1);
//	wj::list<int>::iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	/*const::wj::list<int >clt = lt;
//	wj::list<int>::const_iterator cit = clt.begin();
//	while (cit != clt.end())
//	{
//		(*cit)++;
//		cout << *it << " ";
//		++it;
//	}*/
//}
	//struct A
	//{
	//	A(int a1 = 0, int a2 = 0)
	//		:_a1(a1)
	//		, _a2(a2)
	//	{}

	//	int _a1;
	//	int _a2;
	//};
	//int main()
	//{

	//	wj::list<A> lt1;
	//	lt1.push_back(A(1, 1));
	//	lt1.push_back(A(2, 2));
	//	lt1.push_back(A(3, 3));
	//	lt1.push_back(A(4, 4));

	//	wj::list<A>::iterator cit = lt1.begin();
	//	while (cit != lt1.end())
	//	{
	//		//cout << (*cit)._a1 << " " << (*cit)._a2 << endl;
	//		cout << (cit->_a1) << " " << (*cit)._a2 << endl;

	//		++cit;
	//	}
	//	cout << endl;
	//}
	/*int main()
		
	{
		wj::list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_front(5);
		lt.push_front(6);
		lt.push_front(7);
		lt.push_front(8);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
		lt.pop_front();
		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
		lt.clear();
		lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);
		lt.push_back(40);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		cout << lt.size() << endl;
	}*/
int main()
{
	wj::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	//拷贝构造
	wj::list<int> lt1(lt);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
	
	wj::list<int> lt2;
	lt2.push_back(10);
	lt2.push_back(20);
	lt2.push_back(30);
	lt2.push_back(40);

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
	//lt2再赋值lt1
	lt1 = lt2;

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}