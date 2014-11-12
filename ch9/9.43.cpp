#include <iostream>
#include <string>
using namespace std;

string &rep_str1(string &s, const string& oldVal, const string &newVal);
string &rep_str2(string &s, const string& oldVal, const string &newVal);
int main()
{
	string test_str = " tho and thru are abbrevs ";
	test_str = rep_str2(test_str, "tho", "though");
	cout << test_str << endl;
	test_str = rep_str2(test_str, "thru", "through");
	cout << test_str << endl;
	test_str = rep_str2(test_str, "abbrevs", "abbreviations");
	cout << test_str << endl;
	return 0;
}

// using iterators, insert and erase
string &rep_str1(string &s, const string &oldVal, const string &newVal)
{
	auto iter = s.begin();
	while(iter != s.end())
	{
		if (string(iter, iter + oldVal.size()) == oldVal)
		{
			auto offset = iter - s.begin();
			iter = s.erase(iter, iter + oldVal.size());
			s.insert(iter, newVal.begin(), newVal.end());
			iter = s.begin() + offset + oldVal.size();
		}
		else
		{
			++iter;
		}
	}
	return s;
}

// using index and replace
string &rep_str2(string &s, const string& oldVal, const string &newVal)
{
	auto i = 0;
	while(i < s.size())
	{
		string sub(s, i, oldVal.size());
		if (sub == oldVal)
		{
			auto offset = i;
			s.replace(i, oldVal.size(), newVal);
			i = offset + newVal.size();
		}
		else
		{
			++i;
		}
	}
	return s;
}
