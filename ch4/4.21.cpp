#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (auto &e : ivec)
		e % 2 != 0 ? e *= 2 : e;

	for (const auto &e : ivec)
		cout << e << " ";

	cout << endl;

	return 0;
}