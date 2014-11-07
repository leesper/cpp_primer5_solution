#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
	vector<string> words;
	ifstream fin("input.txt");
	istream_iterator<string> word_iter(fin), eof;
	string word;
	while (word_iter != eof)
	{
		word = *word_iter++;
		words.push_back(word);
	}
	for (const auto &e : words)
		cout << e << " ";
	cout << endl;
	return 0;
}
