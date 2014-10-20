#include <iostream>
#include <cstddef>
using namespace std;
int main()
{
	int ia[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	cout << "using range for of auto: " << endl;
	for (auto &row : ia)
		for (auto col : row)
			cout << col << endl;

	cout << "using for loop subscript style of auto: " << endl;
	for (auto i = 0; i != 3; ++i)
		for (auto j = 0; j != 4; ++j)
			cout << ia[i][j] << endl;

	cout << "using for loop pointer style of auto: " << endl;
	for (auto p = begin(ia); p != end(ia); ++p)
		for (auto q = begin(*p); q != end(*p); ++q)
			cout << *q << endl;


	return 0;
}