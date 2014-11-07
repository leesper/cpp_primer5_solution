#include <iostream>
#include <string>
using namespace std;

int main()
{
	do 
	{
		string word1, word2;
		cin >> word1 >> word2;
		word1 < word2 ? cout << word1 << " is lesser" << endl : cout << word2 << " is lesser" << endl;
	} while (true);
	return 0;
}