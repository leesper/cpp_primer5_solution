#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> svec {"com", "edu", "org", "cn"};
	vector<int> ivec {1, 2, 3, 4};

	vector<pair<string, int>> pvec;
	for (int i = 0; i != ivec.size(); ++i)
	{	// method 1
		//pvec.push_back(make_pair(svec[i], ivec[i]));
		// method 2
		//pvec.push_back(pair<string, int>{svec[i], ivec[i]});
		// method 3
		pvec.push_back(pair<string, int>(svec[i], ivec[i]));
	}

	for (const auto &e : pvec)
		cout << e.first << " " << e.second << endl;

	return 0;
}
