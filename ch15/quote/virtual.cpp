#include <iostream>

class Base
{
public:
	virtual ~Base() {}
	virtual int fcn() = 0;
protected:
	int i = 0;
};

class Derived : public Base
{
public:
	virtual int fcn() { return i + 2;}
};

int main()
{
	Derived d;
	d.fcn();
	return 0;
}
