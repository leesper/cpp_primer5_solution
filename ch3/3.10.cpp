#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string str, res;
	getline(cin, str);
	for (auto c : str)
		if (!ispunct(c))
			res += c;
	cout << res << endl;
	return 0;
}