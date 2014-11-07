#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

int main()
{
	vector<int> ivec {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 5};
	list<int> ilst;
	unique_copy(ivec.begin(), ivec.end(), back_inserter(ilst));
	for (const auto &e : ilst)
		cout << e << endl;
	return 0;
}
