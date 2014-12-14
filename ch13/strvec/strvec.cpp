#include <algorithm>
#include <memory>
#include <iterator>
#include "strvec.h"
using namespace std;

allocator<string> StrVec::alloc;

void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string* b, const string* e)
{
	auto data = alloc.allocate(e - b);
	// {first constructed place, first free place}
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	if (elements)
	{
		//for (auto p = first_free; p != elements; /* empty */)
		//	alloc.destroy(--p);
		for_each(elements, first_free, [this](string &ptr) { alloc.destroy(&ptr); });
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	elements = data.first;
	first_free = cap = data.second;
}

StrVec::StrVec(const initializer_list<string> &ilst):
		elements(alloc.allocate(ilst.size())),
		first_free(uninitialized_copy(ilst.begin(), ilst.end(), elements)),
		cap(first_free)
{}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

StrVec::StrVec(StrVec &&rhs) noexcept:
		elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
	rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if (*this != rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec& StrVec::operator=(const initializer_list<string> &ilst)
{
	auto data = alloc_n_copy(ilst.begin(), ilst.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	auto first = alloc.allocate(newcapacity);
	auto last = uninitialized_copy(
			make_move_iterator(begin()),
			make_move_iterator(end()),
			first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;
	/*
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
	*/
}

void StrVec::reserve(const size_t n)
{
	if (n > capacity())
	{
		auto newdata = alloc.allocate(n);
		auto dest = newdata;
		auto elem = elements;
		for (size_t i = 0; i != size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + n;
	}
}

void StrVec::resize(const size_t n)
{
	resize(n, string());
}

void StrVec::resize(const size_t n, const string &t)
{
	auto newdata = alloc.allocate(n);
	auto remain = uninitialized_copy_n(begin(), min(n, size()), newdata);
	if (n > size())
	{
		uninitialized_fill_n(remain, n - size(), t);
		remain = remain + n - size();
	}
	free();
	elements = newdata;;
	first_free = cap = remain;
}
