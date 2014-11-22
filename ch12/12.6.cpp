#include <vector>
#include <iostream>
using namespace std;

vector<int> *alloc_vec()
{
	auto ptr = new vector<int>;
	return ptr;
}

void read_stdin(vector<int> *pvec)
{
	int num;
	while (cin >> num)
		pvec->push_back(num);
}

void print_vec(vector<int> *pvec)
{
	for (const auto &e : *pvec)
		cout << e << " ";
}

int main()
{
	auto ptr = alloc_vec();
	read_stdin(ptr);
	print_vec(ptr);
	delete ptr;
	return 0;
}
