#include <iostream>
#include <string>
using namespace std;

string &polite1(string &name, const string &pref, const string &suff);
string &polite2(string &name, const string &pref, const string &suff);
int main()
{
	string general = "Patton";
	general = polite2(general, "Gr. ", " Jr");
	cout << general << endl;
	return 0;
}

string &polite1(string &name, const string &pref, const string &suff)
{
	return name.insert(0, pref).append(suff);
}

string &polite2(string &name, const string &pref, const string &suff)
{
	name.insert(0, pref);
	return name.insert(name.size(), suff);
}
