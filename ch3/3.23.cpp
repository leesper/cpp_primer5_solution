#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> ivec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter)
		*iter *= 2;
	for (auto elem : ivec)
		cout << elem << endl;
	return 0;
}