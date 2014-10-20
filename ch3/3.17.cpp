#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string word;
	vector<string> words;

	while (cin >> word)
		words.push_back(word);

	for (auto &str : words) 
		for (auto &ch : str)
			if (isalpha(ch))
				ch = toupper(ch);

	decltype(words.size()) cnt = 0;
	for (auto str : words)
	{
		if (cnt % 8 == 0 && cnt != 0)
			cout << endl;
		cout << str << " ";
		++cnt;
	}
	cout << endl;
	return 0;
}