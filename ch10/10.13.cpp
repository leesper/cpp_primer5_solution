#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool moreThan5(const string& str);
int main()
{
	vector<string> words = {"it", "is", "a", "fine", "day", "today", "there", "are",
	"clouds", "in", "the", "sky"};
	auto after = partition(words.begin(), words.end(), moreThan5);
	for (auto iter = words.begin(); iter != after; ++iter)
		cout << *iter << " ";
	cout << endl;
	return 0;
}

bool moreThan5(const string& str)
{
	return str.size() >= 5;
}
