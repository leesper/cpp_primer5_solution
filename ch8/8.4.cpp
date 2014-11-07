#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	vector<string> lines;
	if (fin)
	{
		string line;
		while (getline(fin, line))
		{
			lines.push_back(line);
		}
	}

	for (const auto &e : lines)
	{
		cout << e << endl;
	}
	fin.close();
	return 0;
}
