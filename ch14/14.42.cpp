#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using namespace std::placeholders;

int main()
{
	vector<int> numbers {0, 1, 2, 1029};
	auto cnt = count_if(numbers.begin(), numbers.end(), bind(greater<int>(), _1, 1024));
	cout << "count of numbers greater than 1024: " << cnt << endl;

	vector<string> words {"pooh", "pooh", "leesper"};
	auto iter = find_if(words.begin(), words.end(), bind(not_equal_to<string>(), _1, "pooh"));
	if (iter != end(words))
	{
		cout << "first word not equal to pooh: " << *iter << endl;
	}
	else
	{
		cout << "not found " << endl;
	}

	vector<int> evens {4, 4, 6, 8, 10};
	for_each(evens.begin(), evens.end(), [](int &n) { n = n * 2; });
	cout << "after muliplies by 2: ";
	for_each(evens.begin(), evens.end(), [&](int e){ cout << e << " "; });
	cout << endl;

	vector<int> divisors {1, 3, 5, 7, 9};
	modulus<int> modulo;
	bool divisible = true;
	for (const auto &div : divisors)
	{
		if (modulo(945, div) != 0)
		{
			divisible = false;
			break;
		}
	}
	divisible ? cout << "divisible" : cout << "not divisible";
	cout << endl;
	return 0;
}
