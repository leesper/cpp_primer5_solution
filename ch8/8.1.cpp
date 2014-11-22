#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
using namespace std;

istream &output(istream &is);
int main()
{
	ifstream fin("input.txt");
	cout << output(fin).good() << endl;
	return 0;
}

istream &output(istream &is)
{
	istream_iterator<string> in_iter(is), eof;
	ostream_iterator<string> out_iter(cout, " ");
	string word = *in_iter++;
	while(in_iter != eof)
	{
		*out_iter++ = word;
		word = *in_iter++;
	}
	*out_iter++ = word;
	cout << endl;
	return is;
}
