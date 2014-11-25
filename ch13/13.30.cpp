#include <iostream>
#include "HasPtr.h"
using namespace std;

int main()
{
	HasPtrValue p1("computer");
	HasPtrValue p2("networks");
	p2 = p1;
	return 0;
}
