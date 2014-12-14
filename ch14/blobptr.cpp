#include "blobptr.h"

shared_ptr<vector<string>>
StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	StrBlobPtr orig(*this);
	++*this;
	return orig;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr orig(*this);
	--*this;
	return orig;
}

StrBlobPtr operator+(StrBlobPtr &lhs, const size_t offset)
{
	StrBlobPtr ret(lhs);
	ret.check(ret.curr + offset, "addtion past end of StrBlobPtr");
	ret.curr += offset;
	return ret;
}

ptrdiff_t operator-(StrBlobPtr &lhs, StrBlobPtr &rhs)
{
	ptrdiff_t diff = lhs.curr - rhs.curr;
	return diff;
}

string StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return p[curr];
}

string *StrBlobPtr::operator->() const
{
	return &this->operator *();
}
