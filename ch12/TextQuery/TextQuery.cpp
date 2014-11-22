#include <sstream>
#include "TextQuery.h"
using namespace std;

TextQuery::TextQuery(ifstream &infile): texts(new vector<string>)
{
	string line, word;
	while (getline(infile, line))
	{
		texts->push_back(line);
		int line_no = texts->size() - 1;
		istringstream is(line);
		while (is >> word)
		{
			auto &linos = wd2no[word];
			if (!linos)
				linos.reset(new set<line_no_t>);
			linos->insert(line_no);
		}
	}
}

QueryResult TextQuery::query(const string &s)
{
	static shared_ptr<set<line_no_t>> nodata(new set<line_no_t>);
	if (wd2no.find(s) == wd2no.end())
		return QueryResult(s, texts, nodata);
	return QueryResult(s, texts, wd2no[s]);
}
