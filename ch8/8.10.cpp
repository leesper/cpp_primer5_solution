#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	string line, word;
	while (getline(fin, line))
	{
		istringstream iss(line);
		while (iss >> word)
			cout << word << " ";
	}
	cout << endl;
	return 0;
}
