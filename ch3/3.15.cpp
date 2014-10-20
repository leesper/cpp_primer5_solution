#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string word;
	vector<string> words;
	while (cin >> word)
	{
		words.push_back(word);
	}
	cout << "Reading " << words.size() << " words into vector" << endl;
	cout << "Content: " << endl;
	for (auto elem : words) 
	{
		cout << elem << endl;
	}
	return 0;
}