#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &svec);
void biggies(vector<string> &words, vector<string>::size_type sz);
bool check_size(const string &s, string::size_type sz);
int main()
{
	vector<string> svec {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	elimDups(svec);
	stable_sort(svec.begin(), svec.end(),
			[](const string &s1, const string &s2) { return s1.size() < s2.size(); });
	cout << "final result: " << endl;
	for (const auto &e : svec)
		cout << e << " ";
	cout << endl;
	return 0;
}

void elimDups(vector<string> &svec)
{
	sort(svec.begin(), svec.end());
	cout << "after sort: " << endl;
	for (const auto &e : svec)
		cout << e << " ";
	cout << endl;

	auto uniq_end = unique(svec.begin(), svec.end());
	cout << "after unique: " << endl;
	for (const auto &e : svec)
		cout << e << " ";
	cout << endl;

	svec.erase(uniq_end, svec.end());
	cout << "after erase: " << endl;
	for (const auto &e : svec)
		cout << e << " ";
	cout << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(),
			[](const string &s1, const string &s2) { return s1.size() < s2.size(); });
	auto moreSzIter = find_if(words.begin(), words.end(),
			bind(check_size, _1, sz));
	auto cnt = words.end() - moreSzIter;
	cout << "count of words > " << sz << endl;
	for_each(moreSzIter, words.end(), [](const string& w) { cout << w << " "; });
	cout << endl;
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}
