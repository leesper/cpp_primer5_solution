#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& rhs);
	HasPtr &operator=(const HasPtr &rhs);
	~HasPtr() { delete ps; }
private:
	string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &rhs)
{
	i = rhs.i;
	ps = new string(*rhs.ps);
}

HasPtr & HasPtr::operator=(const HasPtr &rhs)
{
	if (*this != rhs)
	{
		HasPtr temp(rhs);
		swap(*this, temp);
	}

	return this;
}
