#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

int main()
{
	list<const char*> cl = {"hello", "modern", "c++"};
	vector<string> svec;
	svec.assign(cl.begin(), cl.end());
	for (const auto &e : svec)
		cout << e << endl;
	return 0;
}