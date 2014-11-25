#include <iostream>
#include <algorithm>
#include <vector>
#include "HasPtr.h"
using namespace std;

int main()
{
	vector<HasPtrValue> ptrs;
	ptrs.emplace_back("red");
	ptrs.emplace_back("fox");
	ptrs.emplace_back("jumps");
	ptrs.emplace_back("over");
	ptrs.emplace_back("turtle");
	sort(ptrs.begin(), ptrs.end());
	for (auto &e : ptrs)
		cout << e.getValue() << " ";
	cout << endl;
	return 0;
}
