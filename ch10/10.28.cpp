#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	vector<int> ivec {1, 2, 3, 4, 5, 6, 7, 8, 9};
	deque<int> backDeq, frontDeq, insertDeq;

	copy(ivec.begin(), ivec.end(), back_inserter(backDeq));
	copy(ivec.begin(), ivec.end(), front_inserter(frontDeq));
	copy(ivec.begin(), ivec.end(), inserter(insertDeq, insertDeq.begin()));

	auto iterPrint = [](const int i) { cout << i << " "; };
	cout << "back_inserter result: " << endl;
	for_each(backDeq.begin(), backDeq.end(), iterPrint);
	cout << endl;

	cout << "front_inserter result: " << endl;
	for_each(frontDeq.begin(), frontDeq.end(), iterPrint);
	cout << endl;

	cout << "inserter result: " << endl;
	for_each(insertDeq.begin(), insertDeq.end(), iterPrint);
	cout << endl;

	return 0;
}
