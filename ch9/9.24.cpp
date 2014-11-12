#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	cout << ivec.at(0) << endl
		 << ivec[0] << endl
		 << ivec.front() << endl
		 << *ivec.begin() << endl;

	return 0;

}
