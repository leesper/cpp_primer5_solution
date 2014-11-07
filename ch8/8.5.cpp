#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	vector<string> words;
	if (fin)
	{
		string word;
		while (fin >> word)
		{
			words.push_back(word);
		}
	}

	for (const auto &e : words)
	{
		cout << e << endl;
	}
	fin.close();
	return 0;
}
