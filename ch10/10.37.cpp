#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> lst;
	copy(ivec.crbegin() + 3, ivec.crbegin() + 8, back_inserter(lst));
	for (const auto &e : lst)
		cout << e << " ";
	cout << endl;
	return 0;
}
