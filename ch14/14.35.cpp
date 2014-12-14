#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class PrintString
{
public:
	PrintString(istream &i = cin): is(i) {}
	string operator()()
	{
		string str;
		if (getline(is, str))
			return str;
		return string();
	}
private:
	istream &is;
};

int main()
{
	PrintString func;
	vector<string> svec;
	string str;
	while (!(str = func()).empty())
		svec.push_back(str);
	for (const auto &e : svec)
		cout << e << " ";
	cout << endl;
	return 0;
}
