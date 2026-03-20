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
		delete[] _str;
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
	string(const string& s)
	{
		_str = new char[s._capacity + 1];
		strcpy(_str, s._str);
		_size = s._size;
		_capacity = s._capacity;
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

	void insert(size_t pos,int n , char ch)
	{
		assert(pos<=_size);
		if (_size+n>_capacity)
		{
			reserve(_size + n);
		}
		//挪动数据(1)  涉及强制转化，无符号的-1是很大很大的数
		/*int end = _size+n;
		while (end>=(int)pos)
		{
			_str[end ] = _str[end-n];
			end--;
		}*/
		//挪动数据(2)
		size_t end = _size + n;
		while (end >= pos&&end!=npos)
		{
			_str[end] = _str[end - n];
			end--;
		}
		for (size_t i = pos; i <n+pos; i++)
		{
			_str[i] = ch;
		}
		_size += n;
	}
	void insert(size_t pos, const char *str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (len + _size > _capacity)
		{
			//扩容
			reserve(len+_size);
		}
		size_t end = _size + len;
		//挪动数据
		while (end >= pos && end != npos)
		{
			_str[end] = _str[end -len];
			end--;
		}
		//插入数据
		for (size_t i = 0; i < len ; i++)
		{
			_str[i+pos] = str[i];
		}
		_size += len;

	}
	void erase(size_t pos,size_t len=npos)
	{
		assert(pos<=_size);
		//如果内容过短或len是字符串::npos
		if (len == npos || pos+ len >= _size)
		{
		
			_size = pos;
			_str[_size] = '\0';
		}
		else
		{
			size_t end = pos + len;
			while (end<=_size)
			{
				_str[pos++] = _str[end++];
			}
			_size -= len;
		}
	}
	size_t find(char ch,size_t pos=0)
	{
		assert(pos<_size);
		for (size_t i = pos; i < _size; i++)
		{
			if(_str[i] ==ch)
			{
				return i;
			}
			
		}
		return npos;
		
	}

	size_t find(const char*str ,size_t pos=0)
	{
		assert(pos < _size);
		//strstr(str1是待扫描的序列，str2是包含了需要被匹配的字符串)
		char* ptr = strstr(_str,str);
		if (ptr)
		{
			return ptr - _str;
		}
		else
		{
			return npos;
		}
	}

	//获取子串
	string substr(size_t pos,size_t len=npos)
	{
		assert(pos<_size);
		size_t n= len;
		//len特别大或者超了字符大小，需要的n个空间就是pos——_size有多少算多少
		if (len==npos||len+pos>_size)
		{
			n = _size - pos;
		}
		string tmp;
		tmp.reserve(n);
		for (size_t i = pos; i < pos + n; i++)
		{
			tmp += _str[i];
		}
		return tmp;
	}
	void resize(size_t n,char ch)
	{
		//比原先还小
		if (n<_size)
		{
			_size = n;
			_str[_size] = '\0';
		}
		//n比_size大或者比容量大
		else
		{
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
			_size = n;
			_str[_size] = '\0';
		}
	}
private:
	size_t _size;
	size_t _capacity;
	char* _str;
	public:
	 static size_t npos;
	
 };
	 size_t string::npos = -1;

}