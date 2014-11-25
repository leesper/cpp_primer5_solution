#ifndef HASPTR_H
#define HASPTR_H
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class HasPtrValue
{
	friend void swap(HasPtrValue &lhs, HasPtrValue &rhs);
	friend bool operator<(const HasPtrValue &lhs, const HasPtrValue &rhs);
public:
	HasPtrValue(const string &s = string()):
		ps(new string(s)), i(0) { }
	HasPtrValue(const HasPtrValue &p):
		ps(new string(*p.ps)), i(p.i) { }
	HasPtrValue& operator=(const HasPtrValue &rhs);
	string getValue() { return *ps; }
	~HasPtrValue() { delete ps; }
private:
	string *ps;
	int i;
};

void swap(HasPtrValue &lhs, HasPtrValue &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

bool operator<(const HasPtrValue &lhs, const HasPtrValue &rhs)
{
	return *lhs.ps < *rhs.ps;
}

HasPtrValue &HasPtrValue::operator=(const HasPtrValue &rhs)
{
	HasPtrValue temp(rhs);
	swap(*this, temp);
	return *this;
}


class HasPtrPointer
{
public:
	HasPtrPointer(const string &s = string()):
		ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtrPointer(const HasPtrPointer &p):
		ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtrPointer &operator=(const HasPtrPointer &rhs);
	~HasPtrPointer();
private:
	string *ps;
	int i;
	size_t *use;
};

HasPtrPointer::~HasPtrPointer()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}

HasPtrPointer &HasPtrPointer::operator=(const HasPtrPointer &rhs)
{
	++*rhs.use;
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}
#endif//HASPTR_H
