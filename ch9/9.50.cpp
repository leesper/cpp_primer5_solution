#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> floats {"1.1", "2.2", "3.3", "4.4", "5.5"};
	double sum = 0.0;
	for (const auto &e : floats)
		sum += stod(e, nullptr);
	cout << sum << endl;
	return 0;
}
