#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;

void find_in1(const string &s, const string &t1, const string &t2);
void find_in2(const string &s, const string &t1, const string &t2);
int main()
{
	const string numbers = "0123456789";
	const string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const string mix = "ab2c3d7R4E6";
	find_in1(mix, numbers, alpha);
	cout << endl;
	find_in2(mix, numbers, alpha);
	return 0;
}

void find_in1(const string &s, const string &t1, const string &t2)
{
	for (const auto &t : {t1, t2})
	{
		string::size_type pos = 0;
		while ( (pos = s.find_first_of(t, pos)) != string::npos )
		{
			cout << "found at index " << pos
					<< " element is " << s[pos] << endl;
			++pos;
		}
	}
}

void find_in2(const string &s, const string &t1, const string &t2)
{
	for (const auto &t : {t2, t1})
	{
		string::size_type pos = 0;
		while ( (pos = s.find_first_not_of(t, pos)) != string::npos )
		{
			cout << "found at index " << pos
					<< " element is " << s[pos] << endl;
			++pos;
		}
	}
}
