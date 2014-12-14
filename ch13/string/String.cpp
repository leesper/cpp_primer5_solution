#include <algorithm>
#include <cstring>
#include <iostream>
#include "String.h"
using namespace std;

allocator<char> String::alloc;
ostream& operator<<(ostream &os, const String &str)
{
	if (str.size() > 0)
		os << str.elements;
	else
		os << "";
	return os;
}

bool operator==(const String &lhs, const String &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (size_t i = 0; i != lhs.size(); ++i)
	{
		if (lhs.elements[i] != rhs.elements[i])
			return false;
	}
	return true;
}

bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}

String::String(const char *cstr):
		elements(nullptr), first_free(nullptr), cap(nullptr)
{
	auto data = alloc_n_copy(cstr, cstr + strlen(cstr));
	elements = data.first;
	first_free = cap = data.second;
}

String::String(const String& rhs)
{
	cout << "copy constructor calling" << endl;
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
}

String& String::operator=(const String& rhs)
{
	cout << "copy-assignment constructor calling" << endl;
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

String::String(String &&rhs) noexcept:
		elements(rhs.elements),
		first_free(rhs.first_free),
		cap(rhs.cap)
{
	cout << "move constructor running" << endl;
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

String& String::operator=(String &&rhs) noexcept
{
	cout << "move assignment runnning" << endl;
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

String::~String()
{
	free();
}

pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
	auto newdata = alloc.allocate(e - b);
	return {newdata, uninitialized_copy(b, e, newdata)};
}

void String::free()
{
	for_each(elements, first_free, [&](char c){ alloc.destroy(&c); });
	alloc.deallocate(elements, cap - elements);
}

void String::push_back(const char c)
{
	chk_n_alloc();
	alloc.construct(first_free++, c);
}

void String::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}

void String::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
