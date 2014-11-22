#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		auto p = word_count.insert({word, 1});
		if (!p.second)
			++p.first->second;
	}
	for (const auto &w : word_count)
		cout << w.first << " occurrs " << w.second
			 << ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}
