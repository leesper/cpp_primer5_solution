#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
	list<int> ilist {3, 2, 5, 6, 7, 8, 3, 5, 9, 0, 2, 1, 5, 6};
	deque<int> odd;
	deque<int> even;

	for (auto &e : ilist)
		e % 2 ? odd.push_back(e) : even.push_back(e);

	cout << "odd: ";
	for (auto &e : odd)
		cout << e << " ";
	cout << endl;

	cout << "even: ";
	for (auto &e : even)
		cout << e << " ";
	cout << endl;

	return 0;
}
