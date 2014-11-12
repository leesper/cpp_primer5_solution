#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

void str_append(forward_list<string> &flst, const string &s1, const string &s2);
int main()
{
	forward_list<string> flst1 {"the", "fox", "comes"};
	forward_list<string> flst2 = flst1;

	str_append(flst1, "fox", "gold");
	str_append(flst2, "bird", "silver");

	for (const auto &e : flst1)
		cout << e << " ";
	cout << endl;

	for (const auto &e : flst2)
		cout << e << " ";
	cout << endl;

	return 0;
}

void str_append(forward_list<string> &flst, const string &s1, const string &s2)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();

	while (curr != flst.end())
	{
		if (*curr == s1)
		{
			flst.insert_after(curr, s2);
			return;
		}
		prev = curr;
		++curr;
	}
	flst.insert_after(prev, s2);
}
