#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <memory>
using namespace std;

void filter_out(const string& ifname, const string& odd_fname, const string& even_fname);
int main()
{
	filter_out("numbers.txt", "odd_numbers.txt", "even_numbers.txt");
	return 0;
}

void filter_out(const string& ifname, const string& odd_fname, const string& even_fname)
{
	shared_ptr<ifstream> fin = make_shared<ifstream>(ifname);
	shared_ptr<ofstream> fodd = make_shared<ofstream>(odd_fname);
	shared_ptr<ofstream> feven = make_shared<ofstream>(even_fname);

	istream_iterator<int> in_iter(*fin), eof;
	ostream_iterator<int> odd_iter(*fodd, " ");
	ostream_iterator<int> even_iter(*feven, "\n");

	int num;
	while (in_iter != eof)
	{
		num = *in_iter++;
		num % 2 == 0 ? *even_iter++ = num : *odd_iter++ = num;
	}
}
