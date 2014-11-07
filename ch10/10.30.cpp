#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	istream_iterator<int> in(cin), eof;
	vector<int> ivec;
	while (in != eof)
	{
		ivec.push_back(*in++);
	}

	cout << "original numbers: " << endl;
	for (const auto &e : ivec)
		cout << e << " ";
	cout << endl;

	sort(ivec.begin(), ivec.end());
	ostream_iterator<int> out(cout, " ");
	cout << "sorted numbers: " << endl;
	copy(ivec.begin(), ivec.end(), out);
	cout << endl;

	vector<int> uvec;
	unique_copy(ivec.begin(), ivec.end(), back_inserter(uvec));
	cout << "unique numbers: " << endl;
	copy(uvec.begin(), uvec.end(), out);
	cout << endl;

	return 0;
}
