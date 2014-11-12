#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<char> cvec {'c', 'h', 'i', 'n', 'a'};
	string from(cvec.begin(), cvec.end());
	cout << from << endl;
	return 0;
}
