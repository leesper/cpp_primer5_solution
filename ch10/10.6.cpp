#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	list<int> ilst;
	fill_n(back_inserter(ilst), 10, 3);

	for (const auto &e : ilst)
		cout << e << " ";

	cout << endl;
	return 0;
}