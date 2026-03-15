#pragma once
#include <string.h>
#include<assert.h>
namespace wj
{
	class string
	{
	public:
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		return _str;
	}
	iterator end()
	{
		return _str + _size;
	}
	const iterator begin()const
	{
		return _str;
	}
	const iterator end()const
	{
		return _str + _size;
	}
	//带参数的
	string(const char* str)

		: _size(strlen(str))
		, _capacity(_size)
		, _str(new char[_capacity + 1])
	{
		strcpy(_str,str);
	}
	//无参
	string()

		: _size(0)
		, _capacity(0)
		, _str(new char[1])
	{
		_str[0] = '\0';
	}
	~string()
	{
		delete[]_str;
		_str = nullptr;
		_size = 0;
		_capacity = 0;

	}
	const char* c_str()const
	{
		return _str;
	}
	size_t size()const
	{
		return _size;
	}
	char& operator[] (size_t pos)
	{
		assert(pos>=0&&pos<_size);
		return _str[pos];//出了作用域不销毁,生命周期不会随着函数结束而结束
	}
	const char& operator[] (size_t pos)const
	{
		assert(pos >= 0 && pos < _size);
		return _str[pos];
	}
	
	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];//额外加一个空间以填入'\0'
			memcpy(tmp,_str,_size+1);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	void push_back(char ch)
	{
 		if (_size == _capacity)
		{
			//扩容
			reserve(_capacity==0?8:_capacity*3);
		}
		_str[_size] = ch;
		_size++;
		//一定要加上斜杠0
		_str[_size] = '\0';
	}
	void append(const char*str)
	{
		size_t len = strlen(str)+1;
		if (len+_size>_capacity)
		{
			reserve(len + _size);
		}
		memcpy(_str+_size,str,len);
		_size += len;
	}
	string& operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}
	string& operator+=(const char*str)
	{
		append(str);
		return *this;
	}
private:
	size_t _size;
	size_t _capacity;
	char* _str;
	
 };


}