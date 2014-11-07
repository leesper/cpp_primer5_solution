#include <iostream>
#include <string>
using namespace std;

int main()
{
	string before, after, rep;
	unsigned int cnt = 0, rep_cnt = 0;
	cin >> before;
	++cnt;
	while (cin >> after)
	{
		if (before == after)
		{
			++cnt;
		}
		else
		{
			if (cnt > rep_cnt)
			{
				rep = before;
				rep_cnt = cnt;
			}
			before = after;
			cnt = 1;
		}
	}
	if (rep_cnt > 1)
		cout << rep << " occurred " << rep_cnt << " times" << endl;
	else
		cout << "no word was repeated" << endl;
	return 0;
}