#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "TextQuery.h"
#include "QueryResult.h"
using namespace std;

string usage(const string &pname);
void runQueries(ifstream &infile);
int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << usage(argv[0]) << endl;
		return 1;
	}

	ifstream fin(argv[1]);
	if (!fin)
		return 2;

	runQueries(fin);
	return 0;
}

string usage(const string &pname)
{
	ostringstream usg;
	usg << pname << " file";
	return usg.str();
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	do {
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		cout << tq.query(s) << endl;
	} while (true);
}
