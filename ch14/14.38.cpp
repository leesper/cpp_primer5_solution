#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Bounder
{
public:
	Bounder(size_t lower, size_t upper): lower_(lower), upper_(upper) {}
	bool operator()(const string& s) { return s.size() >= lower_ && s.size() <= upper_; }
private:
	size_t lower_;
	size_t upper_;
};

int main()
{
	ifstream fin("input.txt");
	vector<string> words;
	string word;
	while (fin >> word)
		words.push_back(word);

	size_t cnt1 = 0;
	size_t cnt2 = 0;
	Bounder bound(1, 9);
	for (const auto &e : words)
	{
		if (bound(e))
			++cnt1;
		else
			++cnt2;
	}
	cout << "words size in [1, 9]: " << cnt1 << endl;
	cout << "words size 10 or more: " << cnt2 << endl;
	fin.close();
	return 0;
}
