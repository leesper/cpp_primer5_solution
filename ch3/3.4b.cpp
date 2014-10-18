#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string st1, st2;
	cin >> st1 >> st2;
	if (st1.size() == st2.size())
	{
		cout << "equal in size" << endl;
	}
	else
	{
		if (st1.size() > st2.size())
		{
			cout << st1 << " is longer" << endl;
		}
		else
		{
			cout << st2 << " is longer" << endl;
		}
	}
	return 0;
}