#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz);
int main()
{
	vector<int> ivec {2, 4, 5, 2, 7, 8, 9};
	auto pos = find_if_not(ivec.begin(), ivec.end(), bind(check_size, "Leesper", _1));
	if (pos != ivec.end())
		cout << "first int greater than "
			 << string("Leesper").size()
			 << ": " << *pos << endl;
	else
		cout << "not found" << endl;
	return 0;
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}
