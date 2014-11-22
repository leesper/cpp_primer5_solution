#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include "blob.h"
#include "blobptr.h"
using namespace std;

int main()
{
	ifstream fin("input.txt");
	istream_iterator<string> in_iter(fin), eof;
	StrBlob blob;
	string word = *in_iter++;
	while (in_iter != eof)
	{
		blob.push_back(word);
		word = *in_iter++;
	}
	blob.push_back(word); // last one

	StrBlobPtr iter = blob.begin();
	while (true)
	{
		try
		{
			cout << iter.deref() << " ";
			iter = iter.incr();
		}
		catch(out_of_range &e)
		{
			break;
		}
	}

	cout << endl;
	return 0;
}
