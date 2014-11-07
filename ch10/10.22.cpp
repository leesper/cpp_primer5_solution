#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool leqsz(const string &word, const int sz)
{
	return word.size() <= sz;
}

int main()
{
	vector<string> svec {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	cout << "count of words size <= 6: "
		 << count_if(svec.begin(), svec.end(), bind(leqsz, _1, 6))
		 << endl;
	return 0;
}
