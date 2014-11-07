#include <iostream>
#include <vector>
using namespace std;
using funcType = int(int, int);

auto add(int n1, int n2) -> int 
{
	return n1 + n2;
}

auto subtract(int n1, int n2) -> int
{
	return n1 - n2;
}

auto multiply(int n1, int n2) -> int
{
	return n1 * n2;
}

auto divide(int n1, int n2) -> int
{
	return n1 / n2;
}

int main()
{
	vector<funcType*> funcs;
	funcs.push_back(add);
	funcs.push_back(subtract);
	funcs.push_back(multiply);
	funcs.push_back(divide);

	for (auto iter = funcs.begin(); iter != funcs.end(); ++iter)
	{
		cout << (*iter)(9, 6) << endl;
	}
	return 0;
}