#include <iostream>
#include "strvec.h"
using namespace std;

int main()
{
	StrVec svec {"programming", "is", "fun"};
	cout << "size: " << svec.size() << " "
		 << "capacity: " << svec.capacity() << " "
		 << endl;

	auto cvec = svec;
	cvec.resize(2);
	for(auto iter = cvec.begin(); iter != cvec.end(); ++iter)
		cout << *iter << " ";

	cout << endl;

	svec.resize(6, "empty");
	for (auto iter = svec.begin(); iter != svec.end(); ++iter)
		cout << *iter << " ";

	cout << endl;

	return 0;
}
