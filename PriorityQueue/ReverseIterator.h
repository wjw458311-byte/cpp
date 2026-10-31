#pragma once


namespace wj
{
	template<class Iterator, class Ref,class Ptr >
	class ReverseIterator
	{
	public:
		typedef  ReverseIterator<Iterator, Ref, Ptr > self;
		Iterator _it;
		ReverseIterator(Iterator it)
			:_it(it)
		{
		}
		Ref operator*()
		{
			Iterator tmp = _it;

			return (*--tmp);
		}
		Ptr operator->()
		{
			
			return &(*(--_it));
		}
		self& operator++()
		{
			--_it;

			return *this;
		}
		self operator++(int)
		{
			self tmp = *this;
			--_it;

			return tmp;
		}
		self& operator--()
		{
			++_it;

			return *this;
		}
		self operator--(int)
		{
			self tmp = *this;
			++_it;

			return tmp;
		}
		bool operator!=(const self& s) const
		{
			return _it != s._it;
		}
	};
}