#include <iostream>
#include <initializer_list>
using namespace std;
int produce_sum(initializer_list<int> il)
{
	int sum = 0;
	for (const auto &elem : il)
		sum += elem;
	return sum;
}

int main()
{
	cout << produce_sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;
	return 0;
}