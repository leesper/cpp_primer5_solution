#include <iostream>
#include <string>
#include <memory>
#include <cstring>
using namespace std;

unique_ptr<char[]>
concat_chars(const char *p1, const char *p2)
{
	unique_ptr<char[]> up(new char[strlen(p1) + strlen(p2) + 1]);
	int i = 0;
	while (*p1)
		up[i++] = *p1++;
	while (*p2)
		up[i++] = *p2++;
	up[i] = '\0';
	return up;
}

string
concat_strs(const string &s1, const string &s2)
{
	return s1 + s2;
}

int main()
{
	auto up = concat_chars("computer", " networks");
	cout << "concat_chars: " << up.get() << endl;
	cout << "concat_strs: " << concat_strs("computer", " networks") << endl;
	return 0;
}

