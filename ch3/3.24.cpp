#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (auto iter = ivec.begin(); iter < ivec.end() - 1; ++iter)
		cout << *iter + *(iter + 1) << endl;
	for (auto beg = ivec.begin(), end = ivec.end() - 1; beg != end; ++beg, --end)
		cout << *beg + *end << endl;
	return 0;
}