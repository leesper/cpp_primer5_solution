#include <iostream>
#include <cstddef>
using namespace std;
using int_array_4 = int[4];
int main()
{
	int ia[3][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	cout << "using range for of type alias: " << endl;
	for (int_array_4 &row : ia)
		for (int col : row)
			cout << col << endl;

	cout << "using for loop subscript style of type alias: " << endl;
	for (size_t i = 0; i != 3; ++i)
		for (size_t j = 0; j != 4; ++j)
			cout << ia[i][j] << endl;

	cout << "using for loop pointer style of type alias: " << endl;
	for (int_array_4 *p = begin(ia); p != end(ia); ++p)
		for (int *q = begin(*p); q != end(*p); ++q)
			cout << *q << endl;


	return 0;
}