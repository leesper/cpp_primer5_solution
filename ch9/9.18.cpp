#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	deque<string> sd;
	string word;
	while (cin >> word)
	{
		sd.push_back(word);

		for (auto iter = sd.cbegin(); iter != sd.cend(); ++iter)
			cout << *iter << " ";
	}
	return 0;
}