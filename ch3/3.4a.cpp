#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string st1, st2;
	cin >> st1 >> st2;
	if (st1 == st2)
	{
		cout << "equal" << endl;
	}
	else
	{
		if (st1 > st2)
		{
			cout << st1 << " is larger" << endl;
		}
		else
		{
			cout << st2 << " is larger" << endl;
		}
	}
	return 0;
}