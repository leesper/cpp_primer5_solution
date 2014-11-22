#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <memory>
using namespace std;

string usage(string pname);
bool make_transform(const string &fname, map<string, string> &trans);
bool read_texts(const string &fname, vector<string> &texts);
void do_transform(string &line, map<string, string> &trans);
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		cout << usage(argv[0]) << endl;
		return 1;
	}

	string f_rules = argv[1];
	map<string, string> transform;
	if (!make_transform(f_rules, transform))
	{
		cerr << "error occurred while reading rules" << endl;
		return 2;
	}

	string f_texts = argv[2];
	vector<string> texts;
	if (!read_texts(f_texts, texts))
	{
		cerr << "error occurred while reading texts" << endl;
		return 3;
	}

	for (auto &t : texts)
	{
		do_transform(t, transform);
	}

	for (const auto &t : texts)
		cout << t << endl;

	return 0;
}

string usage(string pname)
{
	ostringstream os;
	os << pname << " rules text";
	return os.str();
}

bool make_transform(const string &fname, map<string, string> &trans)
{
	ifstream fin(fname);
	shared_ptr<ifstream> pfin(&fin, [](ifstream *p) { p->close(); });
	if (!*pfin)
		return false;

	string key;
	string value;
	while (*pfin >> key && getline(*pfin, value))
	{
		if (value.size() >= 1)
			trans[key] = value;
		else
			return false;
	}
	return true;
}

bool read_texts(const string &fname, vector<string> &texts)
{
	ifstream fin(fname);
	shared_ptr<ifstream> pfin(&fin, [](ifstream *p) { p->close(); } );
	if (!*pfin)
		return false;

	string line;
	while (getline(*pfin, line))
		texts.push_back(line);
	return true;
}

void do_transform(string &line, map<string, string> &trans)
{
	for (auto citer = trans.cbegin(); citer != trans.cend(); ++citer)
	{
		istringstream is(line);
		ostringstream os;
		string word;
		while (is >> word)
		{
			if (trans.find(word) != trans.end())
				os << trans[word] << " ";
			else
				os << word << " ";
		}
		line = os.str();
	}
}
