#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

template<typename InputIt, typename T>
InputIt my_find(InputIt beg, InputIt end, const T& value)
{
	for (auto it = beg; it != end; ++it)
	{
		if (*it == value)
			return it;
	}
	return end;
}

int main()
{
	vector<int> ivec {1, 3, 5, 7, 9};
	list<string> slst {"computer", "networks"};
	auto int_iter = my_find(ivec.begin(), ivec.end(), 9);
	if (int_iter != ivec.end())
		cout << "found: " << *int_iter << endl;
	else
		cout << "not found" << endl;
	auto str_iter = my_find(slst.begin(), slst.end(), "console");
	if (str_iter != slst.end())
		cout << "found: " << *str_iter << endl;
	else
		cout << "not found" << endl;
	return 0;
}
