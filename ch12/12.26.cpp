#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{
	size_t n = 20;
	allocator<string> alloc;
	string *const p = alloc.allocate(n);
	string *q = p;
	string s;
	while (cin >> s && q != p + n)
		alloc.construct(q++, s);
	const size_t size = q - p;
	cout << size << endl;
	alloc.deallocate(p, n);
	return 0;
}
