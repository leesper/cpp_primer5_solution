#include <iostream>
#include <vector>
using namespace std;

void print_recur(vector<int>::const_iterator beg, vector<int>::const_iterator end);
int main()
{
	vector<int> svec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print_recur(svec.cbegin(), svec.cend());
	return 0;
}

void print_recur(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
	if (beg == end)
		return;
	cout << *beg << endl;
	print_recur(++beg, end);
}

