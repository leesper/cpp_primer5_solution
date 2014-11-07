#include <iostream>
using namespace std;

void decr(int i);
int main()
{
	decr(6);
	return 0;
}

void decr(int i)
{
	cout << [&]() -> bool
	{
		i > 0 ? --i : i;
		return i == 0;
	}() << endl;
}
