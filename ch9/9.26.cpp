#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> ivec;
	list<int> ilist;
	copy(begin(ia), end(ia), back_inserter(ivec));
	copy(begin(ia), end(ia), back_inserter(ilist));

	auto lst_iter = ilist.begin();
	while(lst_iter != ilist.end())
	{
		*lst_iter % 2 ? lst_iter = ilist.erase(lst_iter) : ++lst_iter;
	}
	for (auto &e : ilist)
		cout << e << " ";
	cout << endl;

	auto vec_iter = ivec.begin();
	while(vec_iter != ivec.end())
	{
		*vec_iter % 2 ? ++vec_iter : vec_iter = ivec.erase(vec_iter);
	}
	for (auto &e : ivec)
		cout << e << " ";
	cout << endl;

	return 0;

}
