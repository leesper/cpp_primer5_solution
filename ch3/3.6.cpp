#include <iostream>
#include <string>
using namespace std;
int main()
{
	string st = "sublime text";
	for (auto &c : st)
		c = 'X';
	cout << st << endl;
	return 0;
}