#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	vector<int> ivec = {2, 4, 5, 3, 5, 6, 2, 3, 1, 3, 4, 5, 3, 4, 3, 1, 4, 5, 3};
	vector<string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

	cout << "count of 3: " << count(ivec.cbegin(), ivec.cend(), 3) << endl;
	cout << "count of red: " << count(svec.cbegin(), svec.cend(), "red") << endl;
	cout << "sum of ivec: " << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;
	return 0;
}
