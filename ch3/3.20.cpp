#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; i++)
		cout << ivec[i] + ivec[i + 1] << endl;
	for (decltype(ivec.size()) i = 0; i <= ivec.size() / 2; i++)
		cout << ivec[i] + ivec[ivec.size() - 1 - i] << endl;
	return 0;
}